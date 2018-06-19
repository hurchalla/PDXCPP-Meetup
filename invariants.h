
#if defined(NDEBUG)
#  define PBC_INVARIANTS_GUARD(INVARIANTS_METHOD_NAME) ((void)0)
#else
#  define PBC_INVARIANTS_GUARD(INVARIANTS_METHOD_NAME) \
      using OuterClassPtrPbcInvariantsGuard = decltype(this); \
      class PbcClassInvariantsGuard { \
      public: \
          explicit PbcClassInvariantsGuard(OuterClassPtrPbcInvariantsGuard ptr)\
             : pOuter(ptr) { pOuter->INVARIANTS_METHOD_NAME(); } \
          ~PbcClassInvariantsGuard() { pOuter->INVARIANTS_METHOD_NAME(); } \
          PbcClassInvariantsGuard(const PbcClassInvariantsGuard&) = delete; \
          PbcClassInvariantsGuard& operator=(const PbcClassInvariantsGuard&) = delete; \
      private: \
          OuterClassPtrPbcInvariantsGuard pOuter; \
      } pbcClassInvariantsGuardObject(this)
#endif
