/* 

                          Firewall Builder

                 Copyright (C) 2011 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id$

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef _ASA8_OBJECT_GROUP_HH
#define _ASA8_OBJECT_GROUP_HH

#include "PIXObjectGroup.h"


namespace fwcompiler {

    class ASA8ObjectGroup : public PIXObjectGroup {
    
public:
        ASA8ObjectGroup() : PIXObjectGroup() { }
        virtual ~ASA8ObjectGroup() {};
        DECLARE_FWOBJECT_SUBTYPE(ASA8ObjectGroup);

        virtual std::string getObjectGroupClass();
        //virtual std::string getObjectGroupHeader();
        //virtual std::string getSrvTypeName();

        virtual QString groupMemberToString(
            libfwbuilder::FWObject *obj, NamedObjectsManager *named_obj_manager)
            throw(libfwbuilder::FWException);

    };
}

#endif