/* Copyright 2020 Open Source Robotics Foundation, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.ros2.rcljava.qos.policies;

public enum Liveliness implements QoSPolicy {
  SYSTEM_DEFAULT(0),
  AUTOMATIC(1),
  MANUAL_BY_TOPIC(3);

  private final int value;

  Liveliness(final int value) {
    this.value = value;
  }

  public int getValue() {
    return value;
  }
}
