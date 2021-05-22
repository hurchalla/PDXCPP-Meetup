class AudioPluginExample {
private:
   BigAudioEffect *pExpiredAudioEffect_ = NULL;
   BigAudioEffect *pActiveAudioEffect_ = NULL;
   BigAudioEffect *pNewAudioEffect_ = NULL;
   ...

public:
   // called by very high priority thread, once per millisecond.  
   void processAudio(float* pInput, float const* pOutput, int sampleFrames)    
   {
      if (pNewAudioEffect_ != NULL) {   // *SHARED* data accessed outside lock
         if (mutex_.try_lock()) {       // Bad idea!! See example_with_asm.h
            if (pNewAudioEffect_ != NULL) {
               pExpiredAudioEffect_ = pActiveAudioEffect_;
               pActiveAudioEffect_ = pNewAudioEffect_;
               pNewAudioEffect_ = NULL;
               // The helper thread must delete the expired audio effect.
               // Delete-ing would take too long in this time critical thread.
            }
            mutex_.unlock();
         }
      }
      pActiveAudioEffect_->process(pInput, pOutput, sampleFrames);
   }

   // very low priority helper thread
   void helperThreadEntry()
   {
      mutex_.lock();
      while (killHelper_ == false) {
         if (pExpiredAudioEffect_) {
            delete pExpiredAudioEffect_;
            pExpiredAudioEffect_ = NULL;
         }
         if (guiParamsChanged_) {
            guiParamsChanged_ = false;
            pNewAudioEffect_ = new BigAudioEffect(guiParams_);
         }
         mutex_.unlock();
         Sleep(100);      // sleep 100 milliseconds
         mutex_.lock();
      }
      mutex_.unlock();
   }
   ...
};


