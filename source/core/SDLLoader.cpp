/*
 * =====================================================================================
 *
 *       Filename:  SDLLoader.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:07:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "SDLHeaders.hpp"
#include "SDLLoader.hpp"

SDLLoader::~SDLLoader() {
	if(m_mixInitialized) Mix_CloseAudio();
}

void SDLLoader::load() {
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
		throw EXCEPTION("SDL mixer init error:", Mix_GetError());
	} else {
		m_mixInitialized = true;
	}

	Mix_AllocateChannels(32);

	Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
	Mix_Volume(-1, MIX_MAX_VOLUME);
}

