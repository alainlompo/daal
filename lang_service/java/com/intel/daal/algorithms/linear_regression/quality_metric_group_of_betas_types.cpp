/* file: quality_metric_group_of_betas_types.cpp */
/*******************************************************************************
* Copyright 2014-2018 Intel Corporation
* All Rights Reserved.
*
* If this  software was obtained  under the  Intel Simplified  Software License,
* the following terms apply:
*
* The source code,  information  and material  ("Material") contained  herein is
* owned by Intel Corporation or its  suppliers or licensors,  and  title to such
* Material remains with Intel  Corporation or its  suppliers or  licensors.  The
* Material  contains  proprietary  information  of  Intel or  its suppliers  and
* licensors.  The Material is protected by  worldwide copyright  laws and treaty
* provisions.  No part  of  the  Material   may  be  used,  copied,  reproduced,
* modified, published,  uploaded, posted, transmitted,  distributed or disclosed
* in any way without Intel's prior express written permission.  No license under
* any patent,  copyright or other  intellectual property rights  in the Material
* is granted to  or  conferred  upon  you,  either   expressly,  by implication,
* inducement,  estoppel  or  otherwise.  Any  license   under such  intellectual
* property rights must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing,  you may not remove or alter this
* notice or  any  other  notice   embedded  in  Materials  by  Intel  or Intel's
* suppliers or licensors in any way.
*
*
* If this  software  was obtained  under the  Apache License,  Version  2.0 (the
* "License"), the following terms apply:
*
* You may  not use this  file except  in compliance  with  the License.  You may
* obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*
* Unless  required  by   applicable  law  or  agreed  to  in  writing,  software
* distributed under the License  is distributed  on an  "AS IS"  BASIS,  WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
* See the   License  for the   specific  language   governing   permissions  and
* limitations under the License.
*******************************************************************************/

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "daal.h"

#include "linear_regression/quality_metric/JGroupOfBetasParameter.h"
#include "linear_regression/quality_metric/JGroupOfBetasInput.h"
#include "linear_regression/quality_metric/JGroupOfBetasInputId.h"
#include "linear_regression/quality_metric/JGroupOfBetasResult.h"
#include "linear_regression/quality_metric/JGroupOfBetasResultId.h"
#include "JComputeMode.h"
#include "common_helpers.h"

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::linear_regression::quality_metric;
using namespace daal::algorithms::linear_regression::quality_metric::group_of_betas;

#define ExpectedResponses com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasInputId_ExpectedResponses
#define PredictedResponses com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasInputId_PredictedResponses
#define PredictedReducedModelResponses com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasInputId_PredictedReducedModelResponses

#define ExpectedMeans com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_ExpectedMeans
#define ExpectedVariance com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_ExpectedVariance
#define RegSS com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_RegSS
#define ResSS com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_ResSS
#define TSS com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_TSS
#define DeterminationCoeff com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_DeterminationCoeff
#define FStatistics com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResultId_FStatistics

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasParameter
* Method:    cSetNBeta
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasParameter_cSetNBeta
(JNIEnv *, jobject, jlong parAddr, jlong nBeta)
{
    (*(group_of_betas::Parameter *)parAddr).numBeta = nBeta;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasParameter
* Method:    cGetNBeta
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasParameter_cGetNBeta
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(group_of_betas::Parameter *)parAddr).numBeta;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasParameter
* Method:    cSetNBetaReducedModel
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasParameter_cSetNBetaReducedModel
(JNIEnv *, jobject, jlong parAddr, jlong nBetaReducedModel)
{
    (*(group_of_betas::Parameter *)parAddr).numBetaReducedModel = nBetaReducedModel;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasParameter
* Method:    cGetNBetaReducedModel
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasParameter_cGetNBetaReducedModel
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(group_of_betas::Parameter *)parAddr).numBetaReducedModel;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasParameter
* Method:    cSetAccuracyThreshold
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasParameter_cSetAccuracyThreshold
(JNIEnv *, jobject, jlong parAddr, jdouble accuracyThreshold)
{
    (*(group_of_betas::Parameter *)parAddr).accuracyThreshold = accuracyThreshold;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasParameter
* Method:    cGetAccuracyThreshold
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasParameter_cGetAccuracyThreshold
(JNIEnv *, jobject, jlong parAddr)
{
    return(jdouble)(*(group_of_betas::Parameter *)parAddr).accuracyThreshold;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasInput
* Method:    cSetInputTable
* Signature: (JIJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasInput_cSetInputTable
(JNIEnv *, jobject, jlong resAddr, jint id, jlong ntAddr)
{
    jniInput<group_of_betas::Input>::set<group_of_betas::DataInputId, NumericTable>(resAddr, id, ntAddr);
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasInput
* Method:    cGetInputTable
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasInput_cGetInputTable
(JNIEnv *, jobject, jlong inputAddr, jint id)
{
    if(id != PredictedResponses && id != ExpectedResponses && id != PredictedReducedModelResponses) return (jlong)0;

    return jniInput<group_of_betas::Input>::get<group_of_betas::DataInputId, NumericTable>(inputAddr, id);
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResult
* Method:    cSetResultTable
* Signature: (JIJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasResult_cSetResultTable
(JNIEnv *, jobject, jlong resAddr, jint id, jlong ntAddr)
{
    jniArgument<group_of_betas::Result>::set<group_of_betas::ResultId, NumericTable>(resAddr, id, ntAddr);
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResult
* Method:    cGetResultTable
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasResult_cGetResultTable
(JNIEnv *, jobject, jlong resAddr, jint id)
{
    if(id == ExpectedMeans)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, expectedMeans);
    if(id == ExpectedVariance)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, expectedVariance);
    if(id == RegSS)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, regSS);
    if(id == ResSS)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, resSS);
    if(id == TSS)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, tSS);
    if(id == DeterminationCoeff)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, determinationCoeff);
    if(id == FStatistics)
        return jniArgument<group_of_betas::Result>::get<group_of_betas::ResultId, NumericTable>(resAddr, fStatistics);
    return (jlong)0;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_GroupOfBetasResult
* Method:    cNewResult
* Signature: ()J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_GroupOfBetasResult_cNewResult
(JNIEnv *, jobject)
{
    return jniArgument<group_of_betas::Result>::newObj();
}
