/* file: memory_block.h */
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

#ifndef __MEMORY_BLOCK_H__
#define __MEMORY_BLOCK_H__

#include "services/daal_defines.h"
#include "data_management/data/data_serialize.h"
#include "data_management/data/data_archive.h"
#include "services/daal_shared_ptr.h"

namespace daal
{
namespace data_management
{

namespace interface1
{

/**
*  <a name="DAAL-CLASS-DATA_MANAGEMENT__MEMORYBLOCK"></a>
*  \brief Serializable memory block, owner of the memory
*/
class DAAL_EXPORT MemoryBlock : public SerializationIface
{
public:
    DECLARE_SERIALIZABLE_TAG();

    DAAL_CAST_OPERATOR(MemoryBlock);

    /** Default constructor */
    MemoryBlock() : _size(0), _value(NULL)
    {
    }

    /** Constructs Memory Block object by allocating memory of size equal to the requested number of bytes
    * \param[in] n Number of bytes to allocate
    */
    MemoryBlock(size_t n);

    virtual ~MemoryBlock();

    /** Allocates given number of bytes.
    * Owned memory is reallocated if its size is less than required
    * \param[in] n Number of bytes to allocate
    * \return Reference to SharedPtr of the SerializationIface type
    */
    void reserve(size_t n);

    /**
    *  Returns pointer to the owned memory
    *  \return Pointer to the owned memory
    */
    byte* get()
    {
        return _value;
    }

    /**
    *  Returns pointer to the owned memory
    *  \return Pointer to the owned memory
    */
    const byte* get() const
    {
        return _value;
    }

    /**
    *  Returns the size of stored memory in bytes
    *  \return Number of stored bytes
    */
    size_t size() const
    {
        return _size;
    }

    /**
    *  Releases owned memory
    */
    void release();

protected:
    virtual services::Status serializeImpl(interface1::InputDataArchive  *arch) DAAL_C11_OVERRIDE
    {
        arch->set(_size);
        if(_size)
            arch->set(_value, _size);

        return services::Status();
    }

    virtual services::Status deserializeImpl(const interface1::OutputDataArchive *arch) DAAL_C11_OVERRIDE
    {
        size_t sz = 0;
        arch->set(sz);
        reserve(sz);
        if(sz)
            arch->set(_value, sz);

        return services::Status();
    }

protected:
    size_t _size;
    byte* _value;
};
typedef services::SharedPtr<MemoryBlock> MemoryBlockPtr;

} // namespace interface1
using interface1::MemoryBlock;
using interface1::MemoryBlockPtr;

}
}

#endif
