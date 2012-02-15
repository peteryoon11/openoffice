/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef SD_ACCESSIBILITY_ACCESSIBLE_SCROLL_PANEL_HXX
#define SD_ACCESSIBILITY_ACCESSIBLE_SCROLL_PANEL_HXX

#include "AccessibleTreeNode.hxx"

namespace sd { namespace toolpanel {
class ScrollPanel;
} }


namespace accessibility {

/** This derived class handles the accessible children different from its
    base class.  It adds the scroll bars as children when they are visible.
*/
class AccessibleScrollPanel
    : public AccessibleTreeNode
{
public:
    AccessibleScrollPanel (
        ::sd::toolpanel::ScrollPanel& rScrollPanel,
        const ::rtl::OUString& rsName,
        const ::rtl::OUString& rsDescription);
    ~AccessibleScrollPanel (void);

	//=====  XAccessibleContext  ==============================================

    ///	Return the number of currently visible children.
    virtual sal_Int32 SAL_CALL
    	getAccessibleChildCount (void) throw (::com::sun::star::uno::RuntimeException);

    ///	Return the specified child or throw exception.
    virtual ::com::sun::star::uno::Reference<
        ::com::sun::star::accessibility::XAccessible> SAL_CALL
    	getAccessibleChild (sal_Int32 nIndex)
        throw (::com::sun::star::lang::IndexOutOfBoundsException,
            ::com::sun::star::uno::RuntimeException);

	//=====  XServiceInfo  ====================================================

    /**	Returns an identifier for the implementation of this object.
    */
	virtual ::rtl::OUString SAL_CALL
    	getImplementationName (void)
        throw (::com::sun::star::uno::RuntimeException);

private:
    ::sd::toolpanel::ScrollPanel& GetScrollPanel (void) const;
};

} // end of namespace accessibility

#endif
