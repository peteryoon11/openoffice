/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/

#include <stdio.h>

#include "sal/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/

// replaced by macros in sal/main.h
void SAL_CALL sal_detail_initialize(int argc, char ** argv) 
{
	printf("Dead code\n");
	exit(1);
}

void SAL_CALL sal_detail_deinitialize()
{
	printf("Dead code\n");
	exit(1);
}

#ifdef __cplusplus
}	// extern "C"
#endif
