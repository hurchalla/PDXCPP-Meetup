
void processAudio(float* pInput, float const* pOutput, int sampleFrames)    
{
  // Yeah I know there's *technically* a data race, but it's benign.
  // pNewAudioEffect_ is only read by this thread.
  // I was extremely careful to check the race will never be a problem!
  
  if (pNewAudioEffect_ != NULL) // mov  rax, QWORD PTR BigAudioEffect * pNewAudioEffect_
                                // mov  QWORD PTR BigAudioEffect * pNewAudioEffect_, rax
                                // cmp  rax, 0
                                // je   .BRANCH_END
  {
     if (mutex_.try_lock()) {
        if (pNewAudioEffect_ != NULL) {
             ...
        }
        mutex_.unlock();
     }
     ...
  }
  ...
}
