/*
 * Copyright 2022 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
package com.amazon.alexa.auto.aacs.common;

import com.squareup.moshi.JsonClass;

@JsonClass(generateAdapter = true)
data class ListTemplateTitle (
        val subTitle: String?,
        val mainTitle: String
)

@JsonClass(generateAdapter = true)
data class ListItem (
        val leftTextField: String,
        val rightTextField: String
)

@JsonClass(generateAdapter = true)
data class ListTemplate (
        val token: String,
        val type: String,
        val title: ListTemplateTitle,
        val  listItems: List<ListItem>
)
