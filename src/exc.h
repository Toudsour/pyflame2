// Copyright 2016 Uber Technologies, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <stdexcept>
#include <string>

namespace pyflame {
    // An expected exception, indicating that Pyflame can exit with status 0.
    class TerminateException : public std::runtime_error {
    public:
        explicit TerminateException(const std::string &what_arg)
            : std::runtime_error(what_arg) {}
    };

    // An unexpected exception, indicating that Pyflame should exit with non-zero
    // status.
    class FatalException : public std::runtime_error {
    public:
        explicit FatalException(const std::string &what_arg)
            : std::runtime_error(what_arg) {}
    };

    class SymbolException : public FatalException {
    public:
        explicit SymbolException(const std::string &what_arg)
            : FatalException(what_arg) {}
    };

    class PtraceException : public std::runtime_error {
    public:
        explicit PtraceException(const std::string &what_arg)
            : std::runtime_error(what_arg) {}
    };
}// namespace pyflame
