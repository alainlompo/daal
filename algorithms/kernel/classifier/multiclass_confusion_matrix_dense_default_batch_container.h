/* file: multiclass_confusion_matrix_dense_default_batch_container.h */
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

/*
//++
//  Implementation of the container for the multi-class confusion matrix.
//--
*/

#ifndef __MULTICLASS_CONFUSION_MATRIX_DENSE_DEFAULT_BATCH_CONTAINER_H__
#define __MULTICLASS_CONFUSION_MATRIX_DENSE_DEFAULT_BATCH_CONTAINER_H__

#include "algorithms/classifier/multiclass_confusion_matrix_batch.h"
#include "multiclass_confusion_matrix_dense_default_batch_kernel.h"

namespace daal
{
namespace algorithms
{
namespace classifier
{
namespace quality_metric
{
namespace multiclass_confusion_matrix
{
template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::BatchContainer(daal::services::Environment::env *daalEnv)
{
    __DAAL_INITIALIZE_KERNELS(internal::MultiClassConfusionMatrixKernel, method, algorithmFPType);
}

template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::~BatchContainer()
{
    __DAAL_DEINITIALIZE_KERNELS();
}

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status BatchContainer<algorithmFPType, method, cpu>::compute()
{
    Input *input = static_cast<Input *>(_in);
    Result *result = static_cast<Result *>(_res);
    Parameter *parameter = static_cast<Parameter *>(_par);
    NumericTable *predictedLabelsTable   = static_cast<NumericTable *>(input->get(predictedLabels  ).get());
    NumericTable *groundTruthLabelsTable = static_cast<NumericTable *>(input->get(groundTruthLabels).get());

    NumericTable *confusionMatrixTable  = static_cast<NumericTable *>(result->get(confusionMatrix).get());
    NumericTable *accuracyMeasuresTable = static_cast<NumericTable *>(result->get(multiClassMetrics).get());

    daal::services::Environment::env &env = *_env;
    __DAAL_CALL_KERNEL(env, internal::MultiClassConfusionMatrixKernel, __DAAL_KERNEL_ARGUMENTS(method, algorithmFPType),   \
                       compute, predictedLabelsTable, groundTruthLabelsTable, confusionMatrixTable, accuracyMeasuresTable, parameter);
}

}
}
}
}
}

#endif
