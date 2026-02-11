#include <cstdio>

#include "tcmalloc/malloc_extension.h"
#include "absl/time/time.h"

extern "C" {
    bool NeedsProcessBackgroundActions() {
        return tcmalloc::MallocExtension::NeedsProcessBackgroundActions();
    }

    void ProcessBackgroundActions() {
        tcmalloc::MallocExtension::ProcessBackgroundActions();
    }

    void PrintStats() {
        const std::string stats = tcmalloc::MallocExtension::GetStats();
        printf("\n>>> Stats:\n%s\n", stats.c_str());
    }

    void SetMaxPerCpuCacheSize(int32_t value) {
        tcmalloc::MallocExtension::SetMaxPerCpuCacheSize(value);
    }

    void SetBackgroundProcessSleepIntervalInSecs(int64_t value) {
        tcmalloc::MallocExtension::SetBackgroundProcessSleepInterval(absl::Seconds(value));
    }
}
