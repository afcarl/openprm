/**
 * Copyright (c) 2010-2011, Billy Okal
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 * This product includes software developed by the author.
 * 4. Neither the name of the author nor the
 * names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//#include "stdafx.h"
#include "plugindefs.h"
#include <rave/plugin.h>

#include "classicprm.h"
#include "prmplanning.h"

using namespace openprm;

InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv) 
{
    
	if( type == OpenRAVE::PT_ProblemInstance && interfacename == "prmplanning" ) 
	{
        return InterfaceBasePtr(new PRMPlanning(penv));
    } /*else if ( type == PT_ProblemInstance && interfacename == "gsprmplanning" ) {
    	return InterfaceBasePtr(new GSPRMPlanning(penv));
    }*/ 
    else if( type == OpenRAVE::PT_Planner && interfacename == "classicprm" ) 
	{
        return InterfaceBasePtr(new ClassicPRM(penv));
    } /*else if ( type == PT_Planner && interfacename == "sblplanner" ) {
		return InterfaceBasePtr(new SBLPlanner(penv));
	} else if ( type == PT_Planner && interfacename == "vprmplanner" ) {
		return InterfaceBasePtr(new VPRMPlanner(penv));
	} else if ( type == PT_Planner && interfacename == "goalsetprm" ) {
		return InterfaceBasePtr(new GoalSetPRM(penv));
	}*/
	
    return InterfaceBasePtr();
}

void GetPluginAttributesValidated(PLUGININFO& info) 
{
	// planners
    info.interfacenames[PT_Planner].push_back("ClassicPRM");
//     info.interfacenames[PT_Planner].push_back("VPRMPlanner");
// 	info.interfacenames[PT_Planner].push_back("SBLPlanner");
// 	info.interfacenames[PT_Planner].push_back("GoalSetPRM");
// 	
	/// problems
	info.interfacenames[PT_ProblemInstance].push_back("PRMPlanning");
// 	info.interfacenames[PT_ProblemInstance].push_back("GSPRMPlanning");
}

RAVE_PLUGIN_API void DestroyPlugin() 
{
    RAVELOG_INFO("destroying openprm plugin\n");
}
