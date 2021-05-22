
void processAudio(float* pInput, float const* pOutput, int sampleFrames)    
{
  // Yeah I know there's *technically* a data race, but it's "benign" (haha, as-if).
  // pNewAudioEffect_ is only read by this thread, so it's "safe" (except that there's
  // no such thing as safety with a data race).
  
  // here's one way it can go wrong:
  // It would be weird but legal for a compiler to product the following asm.  The
  // variable that seemed to be "read-only" would no longer be read-only, and the data
  // race that was never "benign" to begin with, is now obviously dangerous.
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
