//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $Workfile:     $
// $Date:         $
// $NoKeywords: $
//=============================================================================//

#include <vgui/Cursor.h>
#include "clientmode_tfbase.h"
#include <vgui_controls/EditablePanel.h>

namespace vgui
{
	class AnimationController;
}

class ClientModeTFNormal : public ClientModeTFBase
{
DECLARE_CLASS( ClientModeTFNormal, ClientModeTFBase );

private:

	class Viewport : public CBaseViewport
	{
	typedef CBaseViewport BaseClass;
	// Panel overrides.
	public:
		Viewport();
		virtual ~Viewport() {}

		virtual void	OnThink();
		virtual void	CreateDefaultPanels();
		void			ReloadScheme();

		virtual void ApplySchemeSettings( vgui::IScheme *pScheme )
		{
			BaseClass::ApplySchemeSettings( pScheme );

			gHUD.InitColors( pScheme );

			SetPaintBackgroundEnabled( false );
		}

		IViewPortPanel *CreatePanelByName(const char *szPanelName);

	private:
		bool			m_bHumanScheme;
	};

// IClientMode overrides.
public:

	virtual void	Update();
	virtual bool	CreateMove( float flInputSampleTime, CUserCmd *cmd );
	virtual bool	ShouldDrawViewModel( void );
		
	virtual vgui::Panel *GetMinimapParent( void );

	ClientModeTFNormal();
};

extern IClientMode *GetClientModeNormal();