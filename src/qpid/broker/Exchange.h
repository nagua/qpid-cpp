/*
 *
 * Copyright (c) 2006 The Apache Software Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef _Exchange_
#define _Exchange_

#include <boost/shared_ptr.hpp>
#include <qpid/broker/Deliverable.h>
#include <qpid/broker/Queue.h>
#include <qpid/framing/FieldTable.h>

namespace qpid {
    namespace broker {
        class Exchange{
            const std::string name;
        public:
            typedef boost::shared_ptr<Exchange> shared_ptr;

            explicit Exchange(const std::string& _name) : name(_name){}
            virtual ~Exchange(){}
            std::string getName() { return name; }
            virtual std::string getType() = 0;
            virtual void bind(Queue::shared_ptr queue, const string& routingKey, qpid::framing::FieldTable* args) = 0;
            virtual void unbind(Queue::shared_ptr queue, const string& routingKey, qpid::framing::FieldTable* args) = 0;
            virtual void route(Deliverable& msg, const string& routingKey, qpid::framing::FieldTable* args) = 0;
        };
    }
}


#endif
