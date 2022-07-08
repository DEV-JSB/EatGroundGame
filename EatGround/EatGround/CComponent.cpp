#include "pch.h"
#include "CComponent.h"

CComponent::CComponent()
	:m_bRender(false)
{
}

CComponent::CComponent(bool _render)
	:m_bRender(_render)
{
}

CComponent::~CComponent()
{
}
