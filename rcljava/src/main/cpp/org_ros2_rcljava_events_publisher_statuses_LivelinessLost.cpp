// Copyright 2020 Open Source Robotics Foundation, Inc.
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

#include "org_ros2_rcljava_events_publisher_statuses_LivelinessLost.h"

#include <jni.h>
#include <stdlib.h>

#include "rmw/events_statuses/liveliness_lost.h"
#include "rcl/event.h"
#include "rcljava_common/exceptions.hpp"

using rcljava_common::exceptions::rcljava_throw_exception;

JNIEXPORT jlong JNICALL
Java_org_ros2_rcljava_events_publisher_1statuses_LivelinessLost_nativeAllocateRCLStatusEvent(
  JNIEnv * env, jclass)
{
  void * p = malloc(sizeof(rmw_liveliness_lost_status_t));
  if (!p) {
    rcljava_throw_exception(
      env, "java/lang/OutOfMemoryError", "failed to allocate liveliness lost status");
  }
  return reinterpret_cast<jlong>(p);
}

JNIEXPORT void JNICALL
Java_org_ros2_rcljava_events_publisher_1statuses_LivelinessLost_nativeDeallocateRCLStatusEvent(
  JNIEnv *, jclass, jlong handle)
{
  free(reinterpret_cast<void *>(handle));
}

JNIEXPORT void JNICALL
Java_org_ros2_rcljava_events_publisher_1statuses_LivelinessLost_nativeFromRCLEvent(
  JNIEnv * env, jobject self, jlong handle)
{
  auto * p = reinterpret_cast<rmw_liveliness_lost_status_t *>(handle);
  if (!p) {
    rcljava_throw_exception(
      env, "java/lang/IllegalArgumentException", "passed rmw object handle is NULL");
  }
  // TODO(ivanpauno): class and field lookup could be done at startup time
  jclass clazz = env->GetObjectClass(self);
  jfieldID total_count_fid = env->GetFieldID(clazz, "total_count", "I");
  if (env->ExceptionCheck()) {
    return;
  }
  jfieldID total_count_change_fid = env->GetFieldID(clazz, "total_count_change", "I");
  if (env->ExceptionCheck()) {
    return;
  }
  env->SetIntField(self, total_count_fid, p->total_count);
  env->SetIntField(self, total_count_change_fid, p->total_count_change);
}

JNIEXPORT jint JNICALL
Java_org_ros2_rcljava_events_publisher_1statuses_LivelinessLost_nativeGetPublisherEventType(
  JNIEnv *, jclass)
{
  return RCL_PUBLISHER_LIVELINESS_LOST;
}
