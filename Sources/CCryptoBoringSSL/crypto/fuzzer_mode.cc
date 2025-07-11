// Copyright 2025 The BoringSSL Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <CCryptoBoringSSL_crypto.h>

#include "internal.h"


#if defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)
static CRYPTO_atomic_u32 fuzzer_mode_enabled = 0;

int CRYPTO_fuzzer_mode_enabled(void) {
  return CRYPTO_atomic_load_u32(&fuzzer_mode_enabled);
}

void CRYPTO_set_fuzzer_mode(int enabled) {
  CRYPTO_atomic_store_u32(&fuzzer_mode_enabled, !!enabled);
}
#endif  // FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION
