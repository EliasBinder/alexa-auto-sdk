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

import com.squareup.moshi.JsonClass

@JsonClass(generateAdapter = true)
data class BodyTemplateTitle (
        val subTitle: String?,
        val mainTitle: String
)

@JsonClass(generateAdapter = true)
data class Source (
        val size: String,
        val url: String
        )

@JsonClass(generateAdapter = true)
data class ImageAttributes (
        val sources: List<Source>
        )

@JsonClass(generateAdapter = true)
data class ImageStructure (
        val contentDescription: String?,
        val sources: List<Source>
        )

@JsonClass(generateAdapter = true)
data class BodyTemplate (
        val token: String,
        val type: String,
        val title: BodyTemplateTitle,
        val textField: String,
        val image: ImageAttributes?,
        val skillIcon: ImageStructure?
)