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
package com.amazon.alexa.auto.setup.workflow.command;

import static com.amazon.aacsconstants.AssistantConstants.ON_DEVICE_POLICY;

import android.content.Context;
import android.util.Log;

import com.amazon.alexa.auto.apis.alexaCustomAssistant.AssistantManager;
import com.amazon.alexa.auto.apis.app.AlexaApp;
import com.amazon.alexa.auto.apps.common.util.ModuleProvider;
import com.amazon.alexa.auto.setup.workflow.WorkflowMessage;
import com.amazon.alexa.auto.setup.workflow.event.VoiceAssistanceEvent;

/**
 * Command to check if separate address book consent needs to be requested.
 */
public class CheckSeparateAddressBookConsentCommand extends Command {
    private static final String TAG = CheckSeparateAddressBookConsentCommand.class.getSimpleName();
    private final Context mContext;

    public CheckSeparateAddressBookConsentCommand(Context context) {
        super(context);
        mContext = context;
    }

    @Override
    public void execute() {
        if (ModuleProvider.isAlexaCustomAssistantEnabled(mContext)) {
            AlexaApp mApp = AlexaApp.from(mContext);
            if (mApp == null) {
                Log.e(TAG, "Invalid AlexaApp.");
                return;
            }

            if (mApp.getRootComponent().getComponent(AssistantManager.class).isPresent()) {
                AssistantManager assistantManager = mApp.getRootComponent().getComponent(AssistantManager.class).get();
                if (ON_DEVICE_POLICY.equals(assistantManager.getCoAssistantPolicy())) {
                    Log.i(TAG, "Using ON_DEVICE policy. Asking for separate address book consent.");
                    publishEvent(
                            new WorkflowMessage(VoiceAssistanceEvent.SEPARATE_ADDRESSBOOK_CONSENT_SETUP_NOT_FINISHED));
                    return;
                } 
            } 
            Log.i(TAG, "Skipping separate address book consent.");
            publishEvent(new WorkflowMessage(VoiceAssistanceEvent.SEPARATE_ADDRESSBOOK_CONSENT_SETUP_FINISHED));
        }
    }
}
