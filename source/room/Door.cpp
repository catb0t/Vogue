// ******************************************************************************
// Filename:    Door.cpp
// Project:     Vogue
// Author:      Steven Ball
//
// Revision History:
//   Initial Revision - 13/04/16
//
// Copyright (c) 2005-2016, Steven Ball
// ******************************************************************************

#include "Door.h"


Door::Door(Renderer* pRenderer)
{
	m_pRenderer = pRenderer;

	m_length = 0.5f;
	m_width = 0.5f;
	m_height = 0.5f;
}

Door::~Door()
{
}

// Accessors
void Door::SetPosition(vec3 pos)
{
	m_position = pos;
}

vec3 Door::GetPosition()
{
	return m_position;
}

void Door::SetDimensions(float length, float width, float height)
{
	m_length = length;
	m_width = width;
	m_height = height;
}

float Door::GetLength()
{
	return m_length;
}

float Door::GetWidth()
{
	return m_width;
}

float Door::GetHeight()
{
	return m_height;
}

void Door::SetDirection(eDirection direction)
{
	m_direction = direction;
}

eDirection Door::GetDirection()
{
	return m_direction;
}

// Update
void Door::Update(float dt)
{
}

// Render
void Door::Render()
{
	m_pRenderer->SetRenderMode(RM_WIREFRAME);
	m_pRenderer->SetCullMode(CM_NOCULL);
	m_pRenderer->SetLineWidth(1.0f);

	m_pRenderer->PushMatrix();
		m_pRenderer->TranslateWorldMatrix(m_position.x, m_position.y, m_position.z);
		m_pRenderer->ImmediateColourAlpha(1.0f, 1.0f, 0.0f, 1.0f);

		m_pRenderer->EnableImmediateMode(IM_QUADS);
			m_pRenderer->ImmediateNormal(0.0f, 0.0f, -1.0f);
			m_pRenderer->ImmediateVertex(m_length, -m_height, -m_width);
			m_pRenderer->ImmediateVertex(-m_length, -m_height, -m_width);
			m_pRenderer->ImmediateVertex(-m_length, m_height, -m_width);
			m_pRenderer->ImmediateVertex(m_length, m_height, -m_width);

			m_pRenderer->ImmediateNormal(0.0f, 0.0f, 1.0f);
			m_pRenderer->ImmediateVertex(-m_length, -m_height, m_width);
			m_pRenderer->ImmediateVertex(m_length, -m_height, m_width);
			m_pRenderer->ImmediateVertex(m_length, m_height, m_width);
			m_pRenderer->ImmediateVertex(-m_length, m_height, m_width);

			m_pRenderer->ImmediateNormal(1.0f, 0.0f, 0.0f);
			m_pRenderer->ImmediateVertex(m_length, -m_height, m_width);
			m_pRenderer->ImmediateVertex(m_length, -m_height, -m_width);
			m_pRenderer->ImmediateVertex(m_length, m_height, -m_width);
			m_pRenderer->ImmediateVertex(m_length, m_height, m_width);

			m_pRenderer->ImmediateNormal(-1.0f, 0.0f, 0.0f);
			m_pRenderer->ImmediateVertex(-m_length, -m_height, -m_width);
			m_pRenderer->ImmediateVertex(-m_length, -m_height, m_width);
			m_pRenderer->ImmediateVertex(-m_length, m_height, m_width);
			m_pRenderer->ImmediateVertex(-m_length, m_height, -m_width);

			m_pRenderer->ImmediateNormal(0.0f, -1.0f, 0.0f);
			m_pRenderer->ImmediateVertex(-m_length, -m_height, -m_width);
			m_pRenderer->ImmediateVertex(m_length, -m_height, -m_width);
			m_pRenderer->ImmediateVertex(m_length, -m_height, m_width);
			m_pRenderer->ImmediateVertex(-m_length, -m_height, m_width);

			m_pRenderer->ImmediateNormal(0.0f, 1.0f, 0.0f);
			m_pRenderer->ImmediateVertex(m_length, m_height, -m_width);
			m_pRenderer->ImmediateVertex(-m_length, m_height, -m_width);
			m_pRenderer->ImmediateVertex(-m_length, m_height, m_width);
			m_pRenderer->ImmediateVertex(m_length, m_height, m_width);
		m_pRenderer->DisableImmediateMode();
	m_pRenderer->PopMatrix();

	m_pRenderer->SetCullMode(CM_BACK);
}