/* file: covariance_result.cpp */
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
//  Implementation of covariance algorithm and types methods.
//--
*/

#include "covariance_types.h"
#include "serialization_utils.h"
#include "daal_strings.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace covariance
{
namespace interface1
{

__DAAL_REGISTER_SERIALIZATION_CLASS(Result, SERIALIZATION_COVARIANCE_RESULT_ID);
Result::Result() : daal::algorithms::Result(lastResultId + 1)
    {}

/**
    * Returns the final result of the correlation or variance-covariance matrix algorithm
    * \param[in] id   Identifier of the result, \ref ResultId
    * \return Final result that corresponds to the given identifier
    */
NumericTablePtr Result::get(ResultId id) const
{
    return staticPointerCast<NumericTable, SerializationIface>(Argument::get(id));
}

/**
    * Sets the result of the correlation or variance-covariance matrix algorithm
    * \param[in] id        Identifier of the result
    * \param[in] value     Pointer to the object
    */
void Result::set(ResultId id, const NumericTablePtr &value)
{
    Argument::set(id, value);
}

/**
    * Check correctness of the result
    * \param[in] partialResult     Pointer to the partial result arguments structure
    * \param[in] parameter         Pointer to the structure of the parameters of the algorithm
    * \param[in] method            Computation method
    */
services::Status Result::check(const daal::algorithms::PartialResult *partialResult, const daal::algorithms::Parameter *parameter,
            int method) const
{
    const PartialResult *pres = static_cast<const PartialResult *>(partialResult);
    const Parameter *algParameter = static_cast<const Parameter *>(parameter);
    size_t nFeatures = pres->getNumberOfFeatures();

    return checkImpl(nFeatures, algParameter->outputMatrixType);
}

/**
    * Check correctness of the result
    * \param[in] input     Pointer to the structure with input objects
    * \param[in] parameter Pointer to the structure of algorithm parameters
    * \param[in] method    Computation method
    */
services::Status Result::check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter,
            int method) const
{
    const Parameter *algParameter = static_cast<const Parameter *>(parameter);

    size_t nFeatures = (static_cast<const InputIface *>(input))->getNumberOfFeatures();

    return checkImpl(nFeatures, algParameter->outputMatrixType);
}

services::Status Result::checkImpl(size_t nFeatures, OutputMatrixType outputMatrixType) const
{
    int unexpectedLayouts = (int)NumericTableIface::csrArray |
                            (int)NumericTableIface::upperPackedTriangularMatrix |
                            (int)NumericTableIface::lowerPackedTriangularMatrix;
    services::Status s;
    if (outputMatrixType == covarianceMatrix)
    {
        /* Check covariance matrix */
        s |= checkNumericTable(get(covariance).get(),  covarianceStr(), unexpectedLayouts, 0, nFeatures, nFeatures);
        if(!s) return s;
    }
    else if (outputMatrixType == correlationMatrix)
    {
        /* Check correlation matrix */
        s |= checkNumericTable(get(correlation).get(),  correlationStr(), unexpectedLayouts, 0, nFeatures, nFeatures);
        if(!s) return s;
    }

    unexpectedLayouts |= (int)NumericTableIface::upperPackedSymmetricMatrix |
                            (int)NumericTableIface::lowerPackedSymmetricMatrix;

    /* Check mean vector */
    s |= checkNumericTable(get(mean).get(), meanStr(), unexpectedLayouts, 0, nFeatures, 1);
    return s;
}

}//namespace interface1

}//namespace covariance
}// namespace algorithms
}// namespace daal
