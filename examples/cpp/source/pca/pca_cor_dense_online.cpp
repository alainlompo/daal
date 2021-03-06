/* file: pca_cor_dense_online.cpp */
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
!  Content:
!    C++ example of principal component analysis (PCA) using the correlation
!    method in the online processing mode
!
!******************************************************************************/

/**
 * <a name="DAAL-EXAMPLE-CPP-PCA_CORRELATION_DENSE_ONLINE"></a>
 * \example pca_cor_dense_online.cpp
 */

#include "daal.h"
#include "service.h"

using namespace std;
using namespace daal;
using namespace daal::algorithms;

/* Input data set parameters */
const size_t nVectorsInBlock = 250;
const string dataFileName = "../data/online/pca_normalized.csv";

int main(int argc, char *argv[])
{
    checkArguments(argc, argv, 1, &dataFileName);

    /* Initialize FileDataSource<CSVFeatureManager> to retrieve the input data from a .csv file */
    FileDataSource<CSVFeatureManager> dataSource(dataFileName, DataSource::doAllocateNumericTable,
                                                 DataSource::doDictionaryFromContext);

    /* Create an algorithm for principal component analysis using the correlation method */
    pca::Online<> algorithm;

    while(dataSource.loadDataBlock(nVectorsInBlock) == nVectorsInBlock)
    {
        /* Set the input data to the algorithm */
        algorithm.input.set(pca::data, dataSource.getNumericTable());

        /* Update PCA decomposition */
        algorithm.compute();
    }

    /* Finalize computations */
    algorithm.finalizeCompute();

    /* Print the results */
    pca::ResultPtr result = algorithm.getResult();
    printNumericTable(result->get(pca::eigenvalues), "Eigenvalues:");
    printNumericTable(result->get(pca::eigenvectors), "Eigenvectors:");

    return 0;
}
