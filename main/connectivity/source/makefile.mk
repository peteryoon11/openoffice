#**************************************************************
#  
#  Licensed to the Apache Software Foundation (ASF) under one
#  or more contributor license agreements.  See the NOTICE file
#  distributed with this work for additional information
#  regarding copyright ownership.  The ASF licenses this file
#  to you under the Apache License, Version 2.0 (the
#  "License"); you may not use this file except in compliance
#  with the License.  You may obtain a copy of the License at
#  
#    http://www.apache.org/licenses/LICENSE-2.0
#  
#  Unless required by applicable law or agreed to in writing,
#  software distributed under the License is distributed on an
#  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#  KIND, either express or implied.  See the License for the
#  specific language governing permissions and limitations
#  under the License.
#  
#**************************************************************

PRJ=..
PRJNAME=connectivity
TARGET=helper

LANGUAGE_FILELIST=resource/conn_shared_res.src \
resource/conn_error_message.src \
resource/conn_log_res.src \
drivers/hsqldb/hsqlui.src \
drivers/adabas/adabas.xcu \
drivers/mysql/mysql.xcu \
drivers/hsqldb/hsqldb.xcu \
drivers/macab/macab.xcu \
drivers/evoab2/evoab2.xcu \
drivers/odbc/odbc.xcu \
drivers/kab/kab.xcu \
drivers/flat/flat.xcu \
drivers/calc/calc.xcu \
drivers/jdbc/jdbc.xcu \
drivers/dbase/dbase.xcu \
drivers/evoab2/evoab2.xcu \
drivers/ado/ado.xcu


.INCLUDE :	settings.mk

.INCLUDE :	target.mk
