
#if defined(NDEBUG)
#  define PBC_INVARIANTS_CHECK(METHOD_NAME) ((void)0)
#else
#  define PBC_INVARIANTS_CHECK(METHOD_NAME) METHOD_NAME()
#endif


#if defined(NDEBUG)
#  define PBC_INVARIANTS_GUARD(METHOD_NAME) ((void)0)
#else
#  define PBC_INVARIANTS_GUARD(METHOD_NAME) \
      using OuterClassPtrPbcInvariantsGuard = decltype(this); \
      class PbcClassInvariantsGuard { \
      public: \
          explicit PbcClassInvariantsGuard(OuterClassPtrPbcInvariantsGuard ptr)\
             : pOuter(ptr) { pOuter->METHOD_NAME(); } \
          ~PbcClassInvariantsGuard() { pOuter->METHOD_NAME(); } \
          PbcClassInvariantsGuard(const PbcClassInvariantsGuard&) = delete; \
          PbcClassInvariantsGuard& operator=(const PbcClassInvariantsGuard&) = delete; \
      private: \
          OuterClassPtrPbcInvariantsGuard pOuter; \
      } pbcClassInvariantsGuardObject(this)
#endif
