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



#ifndef SD_TOOLPANEL_CONTROLS_RECENT_MASTER_PAGES_SELECTOR_HXX
#define SD_TOOLPANEL_CONTROLS_RECENT_MASTER_PAGES_SELECTOR_HXX

#include "MasterPagesSelector.hxx"

namespace sd { namespace toolpanel { namespace controls {


/** Show the recently used master pages (that are not currently used).
*/
class RecentMasterPagesSelector
    : public MasterPagesSelector
{
public:
    RecentMasterPagesSelector (
        TreeNode* pParent, 
        SdDrawDocument& rDocument,
        ViewShellBase& rBase,
        const ::boost::shared_ptr<MasterPageContainer>& rpContainer);
    virtual ~RecentMasterPagesSelector (void);

    virtual void LateInit (void);

    virtual void GetState (SfxItemSet& rItemSet);

protected:
    DECL_LINK(MasterPageListListener, void*);
    virtual void Fill (ItemList& rItemList);

	using sd::toolpanel::controls::MasterPagesSelector::Fill;

    /** Forward this call to the base class but save and restore the
        currently selected item.
        Assign the given master page to the list of pages.
        @param pMasterPage
            This master page will usually be a member of the list of all
            available master pages as provided by the MasterPageContainer.
        @param rPageList
            The pages to which to assign the master page.  These pages may
            be slides or master pages themselves.
    */
    virtual void AssignMasterPageToPageList (
        SdPage* pMasterPage,
        const ::boost::shared_ptr<std::vector<SdPage*> >& rpPageList);
};

} } } // end of namespace ::sd::toolpanel::controls

#endif
