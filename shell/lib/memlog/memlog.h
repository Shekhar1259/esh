/**
 * Copyright 2022 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#ifndef __MEMLOG_H__
#define __MEMLOG_H__

#include <stdint.h>

typedef enum mode {
  NONE = 0, // No logging
  INP = 1, // Only getc
  OUT = 2, // Only putc
  INP_OUT = 3, // Both getc & putc
} mode_t;

typedef struct rgn_info {
  volatile uint8_t *addr;
  uint32_t size;

  int curr_index;
} rgn_info_t;

/**
 * @brief Initialises memory logging
 *
 * @param addr Starting address of the memory block used for logging
 * @param size Size of the memory block used for logging
 * @param mode Logging mode
 */
void memlog_init(uint8_t *addr, uint32_t size, mode_t mode);

/**
 * @brief Gets a character from memory input buffer
 *
 * @return int Returns char if any, -1 otherwise
 */
int memlog_getc(void);

/**
 * @brief Writes a character to memory
 *
 * @param c Character to be written
 */
void memlog_putc(char c);

#endif // __MEMLOG_H__