// Copyright (c) 2022 by Apex.AI Inc. All rights reserved.
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
//
// SPDX-License-Identifier: Apache-2.0

#ifndef IOX_POSH_POPO_UNTYPED_CLIENT_HPP
#define IOX_POSH_POPO_UNTYPED_CLIENT_HPP

#include "iceoryx_posh/internal/popo/untyped_client_impl.hpp"

namespace iox::posh::experimental
{
class ClientBuilder;
}

namespace iox
{
namespace popo
{
class UntypedClient : public UntypedClientImpl<>
{
    using Impl = UntypedClientImpl<>;

  public:
    using UntypedClientImpl<>::UntypedClientImpl;

    virtual ~UntypedClient() noexcept
    {
        Impl::m_trigger.reset();
    }

  private:
    friend class iox::posh::experimental::ClientBuilder;

    explicit UntypedClient(typename UntypedClientImpl<>::PortType&& port) noexcept
        : UntypedClientImpl<>(std::move(port))
    {
    }
};

} // namespace popo
} // namespace iox

#endif // IOX_POSH_POPO_UNTYPED_CLIENT_HPP
