/*

   honggfuzz - core structures and macros
   -----------------------------------------

   Author: Robert Swiecki <swiecki@google.com>

   Copyright 2010-2015 by Google Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#ifndef _COMMON_H_
#define _COMMON_H_

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/param.h>
#include <sys/types.h>

#define PROG_NAME "honggfuzz"
#define PROG_VERSION "0.4"
#define PROG_AUTHORS "Robert Swiecki <swiecki@google.com> and others, Copyright 2010-2015 by Google Inc. All Rights Reserved."

#define FILE_PLACEHOLDER "___FILE___"

typedef struct {
    char **cmdline;
    char *inputFile;
    bool nullifyStdio;
    bool fuzzStdin;
    bool saveUnique;
    char *fileExtn;
    double flipRate;
    char flipMode;
    char *externalCommand;
    long tmOut;
    long mutationsMax;
    long mutationsCnt;
    long threadsMax;
    long threadsCnt;
    void *ignoreAddr;
    unsigned long asLimit;
    int pid;

    char **files;
    int fileCnt;
} honggfuzz_t;

typedef struct fuzzer_t {
    pid_t pid;
    time_t timeStarted;
    char origFileName[PATH_MAX];
    char fileName[PATH_MAX];
    uint64_t pc;
    uint64_t backtrace;
    uint64_t access;
    int exception;
} fuzzer_t;

#endif