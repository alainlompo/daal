/* file: InitDistributedStep3MasterPlusPlusPartialResult.java */
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

/**
 * @ingroup kmeans_init_distributed
 * @{
 */
package com.intel.daal.algorithms.kmeans.init;

import com.intel.daal.algorithms.ComputeMode;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.services.DaalContext;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.data_management.data.KeyValueDataCollection;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.SerializableBase;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__KMEANS__INIT__INITDISTRIBUTEDSTEP3MASTERPLUSPLUSPARTIALRESULT"></a>
 * @brief Provides methods to access partial results of computing initial centroids for
 *        the K-Means algorithm in the distributed processing mode
 */
public final class InitDistributedStep3MasterPlusPlusPartialResult extends com.intel.daal.algorithms.PartialResult {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    /**
     * Default constructor. Constructs empty object
     * @param context       Context to manage the partial result of computing initial centroids for the K-Means algorithm
     */
    public InitDistributedStep3MasterPlusPlusPartialResult(DaalContext context) {
        super(context);
        this.cObject = cNewPartialResult();
    }

    public InitDistributedStep3MasterPlusPlusPartialResult(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Returns a partial result of computing initial centroids for the K-Means algorithm
     * @param id  Identifier of the partial result object
     * @param key Identifier of the node the object comes from
     * @return    Partial result object that corresponds to the given identifier
     */
    public NumericTable get(InitDistributedStep3MasterPlusPlusPartialResultId id, int key) {
        if (id == InitDistributedStep3MasterPlusPlusPartialResultId.outputOfStep3ForStep4) {
            long tbl = cGetTable(cObject, id.getValue(), key);
            if(tbl == 0)
                return null;
            return (NumericTable)Factory.instance().createObject(getContext(), tbl);
        } else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Returns an partial result for computing initial centroids for the K-Means algorithm
     * in the 3rd step in the distributed processing mode
     * @param id    Identifier of the input object
     */

    public SerializableBase get(InitDistributedStep3MasterPlusPlusPartialResultDataId id) {
        if (id != InitDistributedStep3MasterPlusPlusPartialResultDataId.outputOfStep3ForStep5) {
            throw new IllegalArgumentException("id unsupported");
        }
        long addr = cGetSerializableBase(cObject, id.getValue());
        if(addr == 0)
            return null;
        return Factory.instance().createObject(getContext(), addr);
    }

    /**
    * Returns a partial result object for computing initial centroids for the K-Means algorithm
    * @param id Identifier of the partial result object
    * @return   Partial result object that corresponds to the given identifier
    */
    public KeyValueDataCollection get(InitDistributedStep3MasterPlusPlusPartialResultId id) {
        if (id != InitDistributedStep3MasterPlusPlusPartialResultId.outputOfStep3ForStep4) {
            throw new IllegalArgumentException("id unsupported");
        }
        return new KeyValueDataCollection(getContext(), cGetKeyValueDataCollection(cObject, id.getValue()));
    }

    private native long cNewPartialResult();

    private native long cGetTable(long inputAddr, int id, int key);

    private native long cGetKeyValueDataCollection(long inputAddr, int id);

    private native long cGetSerializableBase(long inputAddr, int id);
}
/** @} */
