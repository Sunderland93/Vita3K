// Vita3K emulator project
// Copyright (C) 2018 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#include "SceGxm.h"

#include <gxm/functions.h>
#include <gxm/types.h>
#include <util/log.h>

#include <glbinding/Binding.h>

using namespace emu;
using namespace glbinding;

EXPORT(int, sceGxmAddRazorGpuCaptureBuffer) {
    return unimplemented("sceGxmAddRazorGpuCaptureBuffer");
}

EXPORT(int, sceGxmBeginCommandList) {
    return unimplemented("sceGxmBeginCommandList");
}

EXPORT(int, sceGxmBeginScene, SceGxmContext *context, unsigned int flags, const SceGxmRenderTarget *renderTarget, const SceGxmValidRegion *validRegion, SceGxmSyncObject *vertexSyncObject, SceGxmSyncObject *fragmentSyncObject, const emu::SceGxmColorSurface *colorSurface, const emu::SceGxmDepthStencilSurface *depthStencil) {
    assert(context != nullptr);
    assert(flags == 0);
    assert(renderTarget != nullptr);
    assert(validRegion == nullptr);
    assert(vertexSyncObject == nullptr);
    assert(fragmentSyncObject != nullptr);
    assert(colorSurface != nullptr);
    assert(depthStencil != nullptr);

    if (host.gxm.isInScene){
        return SCE_GXM_ERROR_WITHIN_SCENE;
    }
    if (depthStencil == nullptr && colorSurface == nullptr){
        return SCE_GXM_ERROR_INVALID_VALUE;
    }
    
    // TODO This may not be right.
    context->fragment_ring_buffer_used = 0;
    context->vertex_ring_buffer_used = 0;
    context->color_surface = *colorSurface;
    
    host.gxm.isInScene = true;
    
    glBindFramebuffer(GL_FRAMEBUFFER, renderTarget->framebuffer[0]);

    // Re-load GL machine settings for multiple contexts support
    switch (context->cull_mode){
    case SCE_GXM_CULL_CCW:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        break;
    case SCE_GXM_CULL_CW:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        break;
    case SCE_GXM_CULL_NONE:
        glDisable(GL_CULL_FACE);
        break;
    }
    
    // TODO This is just for debugging.
    glClear(GL_COLOR_BUFFER_BIT);

    return 0;
}

EXPORT(int, sceGxmBeginSceneEx) {
    return unimplemented("sceGxmBeginSceneEx");
}

EXPORT(int, sceGxmColorSurfaceGetClip) {
    return unimplemented("sceGxmColorSurfaceGetClip");
}

EXPORT(int, sceGxmColorSurfaceGetData) {
    return unimplemented("sceGxmColorSurfaceGetData");
}

EXPORT(int, sceGxmColorSurfaceGetDitherMode) {
    return unimplemented("sceGxmColorSurfaceGetDitherMode");
}

EXPORT(int, sceGxmColorSurfaceGetFormat) {
    return unimplemented("sceGxmColorSurfaceGetFormat");
}

EXPORT(int, sceGxmColorSurfaceGetGammaMode) {
    return unimplemented("sceGxmColorSurfaceGetGammaMode");
}

EXPORT(int, sceGxmColorSurfaceGetScaleMode) {
    return unimplemented("sceGxmColorSurfaceGetScaleMode");
}

EXPORT(int, sceGxmColorSurfaceGetStrideInPixels) {
    return unimplemented("sceGxmColorSurfaceGetStrideInPixels");
}

EXPORT(int, sceGxmColorSurfaceGetType) {
    return unimplemented("sceGxmColorSurfaceGetType");
}

EXPORT(int, sceGxmColorSurfaceInit, emu::SceGxmColorSurface *surface, SceGxmColorFormat colorFormat, SceGxmColorSurfaceType surfaceType, SceGxmColorSurfaceScaleMode scaleMode, SceGxmOutputRegisterSize outputRegisterSize, unsigned int width, unsigned int height, unsigned int strideInPixels, Ptr<void> data) {
    assert(surface != nullptr);
    assert(colorFormat == SCE_GXM_COLOR_FORMAT_A8B8G8R8);
    assert(surfaceType == SCE_GXM_COLOR_SURFACE_LINEAR);
    assert(scaleMode == SCE_GXM_COLOR_SURFACE_SCALE_NONE);
    assert(outputRegisterSize == SCE_GXM_OUTPUT_REGISTER_SIZE_32BIT);
    assert(width > 0);
    assert(height > 0);
    assert(strideInPixels > 0);
    assert(data);

    memset(surface, 0, sizeof(*surface));
    surface->pbeEmitWords[0] = width;
    surface->pbeEmitWords[1] = height;
    surface->pbeEmitWords[2] = strideInPixels;
    surface->pbeEmitWords[3] = data.address();
    surface->outputRegisterSize = outputRegisterSize;

    return 0;
}

EXPORT(int, sceGxmColorSurfaceInitDisabled) {
    return unimplemented("sceGxmColorSurfaceInitDisabled");
}

EXPORT(int, sceGxmColorSurfaceIsEnabled) {
    return unimplemented("sceGxmColorSurfaceIsEnabled");
}

EXPORT(int, sceGxmColorSurfaceSetClip) {
    return unimplemented("sceGxmColorSurfaceSetClip");
}

EXPORT(int, sceGxmColorSurfaceSetData) {
    return unimplemented("sceGxmColorSurfaceSetData");
}

EXPORT(int, sceGxmColorSurfaceSetDitherMode) {
    return unimplemented("sceGxmColorSurfaceSetDitherMode");
}

EXPORT(int, sceGxmColorSurfaceSetFormat) {
    return unimplemented("sceGxmColorSurfaceSetFormat");
}

EXPORT(int, sceGxmColorSurfaceSetGammaMode) {
    return unimplemented("sceGxmColorSurfaceSetGammaMode");
}

EXPORT(int, sceGxmColorSurfaceSetScaleMode) {
    return unimplemented("sceGxmColorSurfaceSetScaleMode");
}

EXPORT(int, sceGxmCreateContext, const emu::SceGxmContextParams *params, Ptr<SceGxmContext> *context) {
    assert(params != nullptr);
    assert(context != nullptr);

    *context = alloc<SceGxmContext>(host.mem, __FUNCTION__);
    if (!*context) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    SceGxmContext *const ctx = context->get(host.mem);
    ctx->params = *params;

    assert(SDL_GL_GetCurrentContext() == nullptr);
    ctx->gl = GLContextPtr(SDL_GL_CreateContext(host.window.get()), SDL_GL_DeleteContext);
    assert(ctx->gl != nullptr);

    Binding::initialize(false);
    setCallbackMaskExcept(CallbackMask::Before | CallbackMask::After, { "glGetError" });
#if MICROPROFILE_ENABLED != 0
    setBeforeCallback(before_callback);
#endif // MICROPROFILE_ENABLED
    setAfterCallback(after_callback);

    LOG_INFO("GL_VERSION = {}", glGetString(GL_VERSION));
	LOG_INFO("GL_SHADING_LANGUAGE_VERSION = {}", glGetString(GL_SHADING_LANGUAGE_VERSION));

    // TODO This is just for debugging.
    glClearColor(0.0625f, 0.125f, 0.25f, 0);

    if (!ctx->texture.init(glGenTextures, glDeleteTextures)) {
        free(host.mem, *context);
        context->reset();

        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    return 0;
}

EXPORT(int, sceGxmCreateDeferredContext) {
    return unimplemented("sceGxmCreateDeferredContext");
}

EXPORT(int, sceGxmCreateRenderTarget, const SceGxmRenderTargetParams *params, Ptr<SceGxmRenderTarget> *renderTarget) {
    assert(params != nullptr);
    assert(renderTarget != nullptr);

    *renderTarget = alloc<SceGxmRenderTarget>(host.mem, __FUNCTION__);
    if (!*renderTarget) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    SceGxmRenderTarget *const rt = renderTarget->get(host.mem);
    if (!rt->renderbuffers.init(glGenRenderbuffers, glDeleteRenderbuffers) || !rt->framebuffer.init(glGenFramebuffers, glDeleteFramebuffers)) {
        free(host.mem, *renderTarget);
        return SCE_GXM_ERROR_DRIVER;
    }

    glBindRenderbuffer(GL_RENDERBUFFER, rt->renderbuffers[0]);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, params->width, params->height);
    glBindRenderbuffer(GL_RENDERBUFFER, rt->renderbuffers[1]);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, params->width, params->height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, rt->framebuffer[0]);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, rt->renderbuffers[0]);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rt->renderbuffers[1]);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return 0;
}

EXPORT(int, sceGxmDepthStencilSurfaceGetBackgroundDepth) {
    return unimplemented("sceGxmDepthStencilSurfaceGetBackgroundDepth");
}

EXPORT(int, sceGxmDepthStencilSurfaceGetBackgroundMask) {
    return unimplemented("sceGxmDepthStencilSurfaceGetBackgroundMask");
}

EXPORT(int, sceGxmDepthStencilSurfaceGetBackgroundStencil) {
    return unimplemented("sceGxmDepthStencilSurfaceGetBackgroundStencil");
}

EXPORT(int, sceGxmDepthStencilSurfaceGetForceLoadMode) {
    return unimplemented("sceGxmDepthStencilSurfaceGetForceLoadMode");
}

EXPORT(int, sceGxmDepthStencilSurfaceGetForceStoreMode) {
    return unimplemented("sceGxmDepthStencilSurfaceGetForceStoreMode");
}

EXPORT(int, sceGxmDepthStencilSurfaceGetFormat) {
    return unimplemented("sceGxmDepthStencilSurfaceGetFormat");
}

EXPORT(int, sceGxmDepthStencilSurfaceGetStrideInSamples) {
    return unimplemented("sceGxmDepthStencilSurfaceGetStrideInSamples");
}

EXPORT(int, sceGxmDepthStencilSurfaceInit, emu::SceGxmDepthStencilSurface *surface, SceGxmDepthStencilFormat depthStencilFormat, SceGxmDepthStencilSurfaceType surfaceType, unsigned int strideInSamples, Ptr<void> depthData, Ptr<void> stencilData) {
    assert(surface != nullptr);
    assert(depthStencilFormat == SCE_GXM_DEPTH_STENCIL_FORMAT_S8D24);
    assert(surfaceType == SCE_GXM_DEPTH_STENCIL_SURFACE_TILED);
    assert(strideInSamples > 0);
    assert(depthData);

    // TODO What to do here?
    memset(surface, 0, sizeof(*surface));
    surface->depthData = depthData;
    surface->stencilData = stencilData;

    return 0;
}

EXPORT(int, sceGxmDepthStencilSurfaceInitDisabled) {
    return unimplemented("sceGxmDepthStencilSurfaceInitDisabled");
}

EXPORT(int, sceGxmDepthStencilSurfaceIsEnabled) {
    return unimplemented("sceGxmDepthStencilSurfaceIsEnabled");
}

EXPORT(int, sceGxmDepthStencilSurfaceSetBackgroundDepth) {
    return unimplemented("sceGxmDepthStencilSurfaceSetBackgroundDepth");
}

EXPORT(int, sceGxmDepthStencilSurfaceSetBackgroundMask) {
    return unimplemented("sceGxmDepthStencilSurfaceSetBackgroundMask");
}

EXPORT(int, sceGxmDepthStencilSurfaceSetBackgroundStencil) {
    return unimplemented("sceGxmDepthStencilSurfaceSetBackgroundStencil");
}

EXPORT(int, sceGxmDepthStencilSurfaceSetForceLoadMode) {
    return unimplemented("sceGxmDepthStencilSurfaceSetForceLoadMode");
}

EXPORT(int, sceGxmDepthStencilSurfaceSetForceStoreMode) {
    return unimplemented("sceGxmDepthStencilSurfaceSetForceStoreMode");
}

EXPORT(int, sceGxmDestroyContext, Ptr<SceGxmContext> context) {
    assert(context);

    free(host.mem, context);

    return 0;
}

EXPORT(int, sceGxmDestroyDeferredContext) {
    return unimplemented("sceGxmDestroyDeferredContext");
}

EXPORT(int, sceGxmDestroyRenderTarget, Ptr<SceGxmRenderTarget> renderTarget) {
    MemState &mem = host.mem;
    assert(renderTarget);

    free(mem, renderTarget);

    return 0;
}

EXPORT(void, sceGxmDisplayQueueAddEntry, SceGxmSyncObject *oldBuffer, SceGxmSyncObject *newBuffer, Ptr<const void> callbackData) {
    assert(oldBuffer != nullptr);
    assert(newBuffer != nullptr);
    assert(callbackData);

    const Address callback_data_address = callbackData.address();
    const Address callback_pc = host.gxm.params.displayQueueCallback.address();

    const ThreadStatePtr thread = lock_and_find(thread_id, host.kernel.threads, host.kernel.mutex);
    write_reg(*thread->cpu, 0, callback_data_address);
    write_pc(*thread->cpu, callback_pc);

    // TODO Return success if/when we call callback not as a tail call.
}

EXPORT(int, sceGxmDisplayQueueFinish) {
    return 0;
}

EXPORT(int, sceGxmDraw, SceGxmContext *context, SceGxmPrimitiveType primType, SceGxmIndexFormat indexType, const void *indexData, unsigned int indexCount) {
    assert(context != nullptr);
    assert(indexData != nullptr);

    if (!host.gxm.isInScene){
        return SCE_GXM_ERROR_NOT_WITHIN_SCENE;
    }
    
    const GLenum mode = translate_primitive(primType);
    const GLenum type = indexType == SCE_GXM_INDEX_FORMAT_U16 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT;
    glDrawElements(mode, indexCount, type, indexData);

    return 0;
}

EXPORT(int, sceGxmDrawInstanced) {
    return unimplemented("sceGxmDrawInstanced");
}

EXPORT(int, sceGxmDrawPrecomputed) {
    return unimplemented("sceGxmDrawPrecomputed");
}

EXPORT(int, sceGxmEndCommandList) {
    return unimplemented("sceGxmEndCommandList");
}

EXPORT(int, sceGxmEndScene, SceGxmContext *context, const emu::SceGxmNotification *vertexNotification, const emu::SceGxmNotification *fragmentNotification) {
    const MemState &mem = host.mem;
    assert(context != nullptr);
    assert(vertexNotification == nullptr);
    assert(fragmentNotification == nullptr);

    if (!host.gxm.isInScene){
        return SCE_GXM_ERROR_NOT_WITHIN_SCENE;
    }
    
    const GLsizei width = context->color_surface.pbeEmitWords[0];
    const GLsizei height = context->color_surface.pbeEmitWords[1];
    const GLsizei stride_in_pixels = context->color_surface.pbeEmitWords[2];
    const Address data = context->color_surface.pbeEmitWords[3];
    uint32_t *const pixels = Ptr<uint32_t>(data).get(mem);
    glPixelStorei(GL_PACK_ROW_LENGTH, stride_in_pixels); // TODO Reset to 0?
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    flip_vertically(pixels, width, height, stride_in_pixels);

    host.gxm.isInScene = false;
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return 0;
}

EXPORT(int, sceGxmExecuteCommandList) {
    return unimplemented("sceGxmExecuteCommandList");
}

EXPORT(void, sceGxmFinish, SceGxmContext *context) {
    assert(context != nullptr);
}

EXPORT(int, sceGxmFragmentProgramGetPassType) {
    return unimplemented("sceGxmFragmentProgramGetPassType");
}

EXPORT(int, sceGxmFragmentProgramGetProgram) {
    return unimplemented("sceGxmFragmentProgramGetProgram");
}

EXPORT(int, sceGxmFragmentProgramIsEnabled) {
    return unimplemented("sceGxmFragmentProgramIsEnabled");
}

EXPORT(int, sceGxmGetContextType) {
    return unimplemented("sceGxmGetContextType");
}

EXPORT(int, sceGxmGetDeferredContextFragmentBuffer) {
    return unimplemented("sceGxmGetDeferredContextFragmentBuffer");
}

EXPORT(int, sceGxmGetDeferredContextVdmBuffer) {
    return unimplemented("sceGxmGetDeferredContextVdmBuffer");
}

EXPORT(int, sceGxmGetDeferredContextVertexBuffer) {
    return unimplemented("sceGxmGetDeferredContextVertexBuffer");
}

EXPORT(int, sceGxmGetNotificationRegion) {
    return unimplemented("sceGxmGetNotificationRegion");
}

EXPORT(int, sceGxmGetParameterBufferThreshold) {
    return unimplemented("sceGxmGetParameterBufferThreshold");
}

EXPORT(int, sceGxmGetPrecomputedDrawSize) {
    return unimplemented("sceGxmGetPrecomputedDrawSize");
}

EXPORT(int, sceGxmGetPrecomputedFragmentStateSize) {
    return unimplemented("sceGxmGetPrecomputedFragmentStateSize");
}

EXPORT(int, sceGxmGetPrecomputedVertexStateSize) {
    return unimplemented("sceGxmGetPrecomputedVertexStateSize");
}

EXPORT(int, sceGxmGetRenderTargetMemSizes) {
    return unimplemented("sceGxmGetRenderTargetMemSizes");
}

EXPORT(int, sceGxmInitialize, const emu::SceGxmInitializeParams *params) {
    assert(params != nullptr);

    host.gxm.params = *params;

    return 0;
}

EXPORT(int, sceGxmIsDebugVersion) {
    return unimplemented("sceGxmIsDebugVersion");
}

EXPORT(int, sceGxmMapFragmentUsseMemory, Ptr<void> base, SceSize size, unsigned int *offset) {
    assert(base);
    assert(size > 0);
    assert(offset != nullptr);

    // TODO What should this be?
    *offset = base.address();

    return 0;
}

EXPORT(int, sceGxmMapMemory, void *base, SceSize size, SceGxmMemoryAttribFlags attr) {
    assert(base != nullptr);
    assert(size > 0);
    assert((attr == SCE_GXM_MEMORY_ATTRIB_READ) || (attr == SCE_GXM_MEMORY_ATTRIB_RW));

    return 0;
}

EXPORT(int, sceGxmMapVertexUsseMemory, Ptr<void> base, SceSize size, unsigned int *offset) {
    assert(base);
    assert(size > 0);
    assert(offset != nullptr);

    // TODO What should this be?
    *offset = base.address();

    return 0;
}

EXPORT(int, sceGxmMidSceneFlush) {
    return unimplemented("sceGxmMidSceneFlush");
}

EXPORT(int, sceGxmNotificationWait) {
    return unimplemented("sceGxmNotificationWait");
}

EXPORT(int, sceGxmPadHeartbeat, const emu::SceGxmColorSurface *displaySurface, SceGxmSyncObject *displaySyncObject) {
    assert(displaySurface != nullptr);
    assert(displaySyncObject != nullptr);

    return 0;
}

EXPORT(int, sceGxmPadTriggerGpuPaTrace) {
    return unimplemented("sceGxmPadTriggerGpuPaTrace");
}

EXPORT(int, sceGxmPopUserMarker) {
    return unimplemented("sceGxmPopUserMarker");
}

EXPORT(int, sceGxmPrecomputedDrawInit) {
    return unimplemented("sceGxmPrecomputedDrawInit");
}

EXPORT(int, sceGxmPrecomputedDrawSetAllVertexStreams) {
    return unimplemented("sceGxmPrecomputedDrawSetAllVertexStreams");
}

EXPORT(int, sceGxmPrecomputedDrawSetParams) {
    return unimplemented("sceGxmPrecomputedDrawSetParams");
}

EXPORT(int, sceGxmPrecomputedDrawSetParamsInstanced) {
    return unimplemented("sceGxmPrecomputedDrawSetParamsInstanced");
}

EXPORT(int, sceGxmPrecomputedDrawSetVertexStream) {
    return unimplemented("sceGxmPrecomputedDrawSetVertexStream");
}

EXPORT(int, sceGxmPrecomputedFragmentStateGetDefaultUniformBuffer) {
    return unimplemented("sceGxmPrecomputedFragmentStateGetDefaultUniformBuffer");
}

EXPORT(int, sceGxmPrecomputedFragmentStateInit) {
    return unimplemented("sceGxmPrecomputedFragmentStateInit");
}

EXPORT(int, sceGxmPrecomputedFragmentStateSetAllAuxiliarySurfaces) {
    return unimplemented("sceGxmPrecomputedFragmentStateSetAllAuxiliarySurfaces");
}

EXPORT(int, sceGxmPrecomputedFragmentStateSetAllTextures) {
    return unimplemented("sceGxmPrecomputedFragmentStateSetAllTextures");
}

EXPORT(int, sceGxmPrecomputedFragmentStateSetAllUniformBuffers) {
    return unimplemented("sceGxmPrecomputedFragmentStateSetAllUniformBuffers");
}

EXPORT(int, sceGxmPrecomputedFragmentStateSetDefaultUniformBuffer) {
    return unimplemented("sceGxmPrecomputedFragmentStateSetDefaultUniformBuffer");
}

EXPORT(int, sceGxmPrecomputedFragmentStateSetTexture) {
    return unimplemented("sceGxmPrecomputedFragmentStateSetTexture");
}

EXPORT(int, sceGxmPrecomputedFragmentStateSetUniformBuffer) {
    return unimplemented("sceGxmPrecomputedFragmentStateSetUniformBuffer");
}

EXPORT(int, sceGxmPrecomputedVertexStateGetDefaultUniformBuffer) {
    return unimplemented("sceGxmPrecomputedVertexStateGetDefaultUniformBuffer");
}

EXPORT(int, sceGxmPrecomputedVertexStateInit) {
    return unimplemented("sceGxmPrecomputedVertexStateInit");
}

EXPORT(int, sceGxmPrecomputedVertexStateSetAllTextures) {
    return unimplemented("sceGxmPrecomputedVertexStateSetAllTextures");
}

EXPORT(int, sceGxmPrecomputedVertexStateSetAllUniformBuffers) {
    return unimplemented("sceGxmPrecomputedVertexStateSetAllUniformBuffers");
}

EXPORT(int, sceGxmPrecomputedVertexStateSetDefaultUniformBuffer) {
    return unimplemented("sceGxmPrecomputedVertexStateSetDefaultUniformBuffer");
}

EXPORT(int, sceGxmPrecomputedVertexStateSetTexture) {
    return unimplemented("sceGxmPrecomputedVertexStateSetTexture");
}

EXPORT(int, sceGxmPrecomputedVertexStateSetUniformBuffer) {
    return unimplemented("sceGxmPrecomputedVertexStateSetUniformBuffer");
}

EXPORT(int, sceGxmProgramCheck, const SceGxmProgram *program) {
    assert(program != nullptr);

    assert(memcmp(program->magic, "GXP", 4) == 0);
    assert(program->maybe_version[0] == 1);
    assert(program->maybe_version[1] == 4);
    assert(program->maybe_padding[0] == 0);
    assert(program->maybe_padding[1] == 0);

    return 0;
}

EXPORT(Ptr<SceGxmProgramParameter>, sceGxmProgramFindParameterByName, const SceGxmProgram *program, const char *name) {
    const MemState &mem = host.mem;
    assert(program != nullptr);
    assert(name != nullptr);

    const SceGxmProgramParameter *const parameters = reinterpret_cast<const SceGxmProgramParameter *>(reinterpret_cast<const uint8_t *>(&program->parameters_offset) + program->parameters_offset);
    for (uint32_t i = 0; i < program->parameter_count; ++i) {
        const SceGxmProgramParameter *const parameter = &parameters[i];
        const uint8_t *const parameter_bytes = reinterpret_cast<const uint8_t *>(parameter);
        const char *const parameter_name = reinterpret_cast<const char *>(parameter_bytes + parameter->name_offset);
        if (strcmp(parameter_name, name) == 0) {
            const Address parameter_address = static_cast<Address>(parameter_bytes - &mem.memory[0]);
            return Ptr<SceGxmProgramParameter>(parameter_address);
        }
    }

    return Ptr<SceGxmProgramParameter>();
}

EXPORT(int, sceGxmProgramFindParameterBySemantic) {
    return unimplemented("sceGxmProgramFindParameterBySemantic");
}

EXPORT(int, sceGxmProgramGetDefaultUniformBufferSize) {
    return unimplemented("sceGxmProgramGetDefaultUniformBufferSize");
}

EXPORT(int, sceGxmProgramGetFragmentProgramInputs) {
    return unimplemented("sceGxmProgramGetFragmentProgramInputs");
}

EXPORT(int, sceGxmProgramGetOutputRegisterFormat) {
    return unimplemented("sceGxmProgramGetOutputRegisterFormat");
}

EXPORT(int, sceGxmProgramGetParameter) {
    return unimplemented("sceGxmProgramGetParameter");
}

EXPORT(int, sceGxmProgramGetParameterCount) {
    return unimplemented("sceGxmProgramGetParameterCount");
}

EXPORT(int, sceGxmProgramGetSize) {
    return unimplemented("sceGxmProgramGetSize");
}

EXPORT(int, sceGxmProgramGetType) {
    return unimplemented("sceGxmProgramGetType");
}

EXPORT(int, sceGxmProgramGetVertexProgramOutputs) {
    return unimplemented("sceGxmProgramGetVertexProgramOutputs");
}

EXPORT(int, sceGxmProgramIsDepthReplaceUsed) {
    return unimplemented("sceGxmProgramIsDepthReplaceUsed");
}

EXPORT(int, sceGxmProgramIsDiscardUsed) {
    return unimplemented("sceGxmProgramIsDiscardUsed");
}

EXPORT(int, sceGxmProgramIsEquivalent) {
    return unimplemented("sceGxmProgramIsEquivalent");
}

EXPORT(int, sceGxmProgramIsFragColorUsed) {
    return unimplemented("sceGxmProgramIsFragColorUsed");
}

EXPORT(int, sceGxmProgramIsNativeColorUsed) {
    return unimplemented("sceGxmProgramIsNativeColorUsed");
}

EXPORT(int, sceGxmProgramIsSpriteCoordUsed) {
    return unimplemented("sceGxmProgramIsSpriteCoordUsed");
}

EXPORT(int, sceGxmProgramParameterGetArraySize) {
    return unimplemented("sceGxmProgramParameterGetArraySize");
}

EXPORT(int, sceGxmProgramParameterGetCategory) {
    return unimplemented("sceGxmProgramParameterGetCategory");
}

EXPORT(int, sceGxmProgramParameterGetComponentCount) {
    return unimplemented("sceGxmProgramParameterGetComponentCount");
}

EXPORT(int, sceGxmProgramParameterGetContainerIndex) {
    return unimplemented("sceGxmProgramParameterGetContainerIndex");
}

EXPORT(int, sceGxmProgramParameterGetIndex) {
    return unimplemented("sceGxmProgramParameterGetIndex");
}

EXPORT(int, sceGxmProgramParameterGetName) {
    return unimplemented("sceGxmProgramParameterGetName");
}

EXPORT(unsigned int, sceGxmProgramParameterGetResourceIndex, const SceGxmProgramParameter *parameter) {
    assert(parameter != nullptr);

    return parameter->resource_index;
}

EXPORT(int, sceGxmProgramParameterGetSemantic) {
    return unimplemented("sceGxmProgramParameterGetSemantic");
}

EXPORT(int, sceGxmProgramParameterGetSemanticIndex) {
    return unimplemented("sceGxmProgramParameterGetSemanticIndex");
}

EXPORT(int, sceGxmProgramParameterGetType) {
    return unimplemented("sceGxmProgramParameterGetType");
}

EXPORT(int, sceGxmProgramParameterIsRegFormat) {
    return unimplemented("sceGxmProgramParameterIsRegFormat");
}

EXPORT(int, sceGxmProgramParameterIsSamplerCube) {
    return unimplemented("sceGxmProgramParameterIsSamplerCube");
}

EXPORT(int, sceGxmPushUserMarker) {
    return unimplemented("sceGxmPushUserMarker");
}

EXPORT(int, sceGxmRemoveRazorGpuCaptureBuffer) {
    return unimplemented("sceGxmRemoveRazorGpuCaptureBuffer");
}

EXPORT(int, sceGxmRenderTargetGetDriverMemBlock) {
    return unimplemented("sceGxmRenderTargetGetDriverMemBlock");
}

EXPORT(int, sceGxmReserveFragmentDefaultUniformBuffer, SceGxmContext *context, Ptr<void> *uniformBuffer) {
    assert(context != nullptr);
    assert(uniformBuffer != nullptr);

    const size_t size = 64; // TODO I guess this must be in the fragment program.
    const size_t next_used = context->fragment_ring_buffer_used + size;
    assert(next_used <= context->params.fragmentRingBufferMemSize);
    if (next_used > context->params.fragmentRingBufferMemSize) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    *uniformBuffer = context->params.fragmentRingBufferMem.cast<uint8_t>() + static_cast<int32_t>(context->fragment_ring_buffer_used);
    context->fragment_ring_buffer_used = next_used;

    return 0;
}

EXPORT(int, sceGxmRenderTargetGetHostMem) {
    return unimplemented("sceGxmRenderTargetGetHostMem");
}

EXPORT(int, sceGxmReserveVertexDefaultUniformBuffer, SceGxmContext *context, Ptr<void> *uniformBuffer) {
    assert(context != nullptr);
    assert(uniformBuffer != nullptr);

    const size_t size = 64; // TODO I guess this must be in the vertex program.
    const size_t next_used = context->vertex_ring_buffer_used + size;
    assert(next_used <= context->params.vertexRingBufferMemSize);
    if (next_used > context->params.vertexRingBufferMemSize) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    *uniformBuffer = context->params.vertexRingBufferMem.cast<uint8_t>() + static_cast<int32_t>(context->vertex_ring_buffer_used);
    context->vertex_ring_buffer_used = next_used;

    return 0;
}

EXPORT(int, sceGxmSetAuxiliarySurface) {
    return unimplemented("sceGxmSetAuxiliarySurface");
}

EXPORT(int, sceGxmSetBackDepthBias) {
    return unimplemented("sceGxmSetBackDepthBias");
}

EXPORT(int, sceGxmSetBackDepthFunc) {
    return unimplemented("sceGxmSetBackDepthFunc");
}

EXPORT(int, sceGxmSetBackDepthWriteEnable) {
    return unimplemented("sceGxmSetBackDepthWriteEnable");
}

EXPORT(int, sceGxmSetBackFragmentProgramEnable) {
    return unimplemented("sceGxmSetBackFragmentProgramEnable");
}

EXPORT(int, sceGxmSetBackLineFillLastPixelEnable) {
    return unimplemented("sceGxmSetBackLineFillLastPixelEnable");
}

EXPORT(int, sceGxmSetBackPointLineWidth) {
    return unimplemented("sceGxmSetBackPointLineWidth");
}

EXPORT(int, sceGxmSetBackPolygonMode) {
    return unimplemented("sceGxmSetBackPolygonMode");
}

EXPORT(int, sceGxmSetBackStencilFunc) {
    return unimplemented("sceGxmSetBackStencilFunc");
}

EXPORT(int, sceGxmSetBackStencilRef) {
    return unimplemented("sceGxmSetBackStencilRef");
}

EXPORT(int, sceGxmSetBackVisibilityTestEnable) {
    return unimplemented("sceGxmSetBackVisibilityTestEnable");
}

EXPORT(int, sceGxmSetBackVisibilityTestIndex) {
    return unimplemented("sceGxmSetBackVisibilityTestIndex");
}

EXPORT(int, sceGxmSetBackVisibilityTestOp) {
    return unimplemented("sceGxmSetBackVisibilityTestOp");
}

EXPORT(int, sceGxmSetCullMode, SceGxmContext *context, SceGxmCullMode mode) {
    context->cull_mode = mode;
    switch (mode){
    case SCE_GXM_CULL_CCW:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        break;
    case SCE_GXM_CULL_CW:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        break;
    case SCE_GXM_CULL_NONE:
        glDisable(GL_CULL_FACE);
        break;
    }
    return 0;
}

EXPORT(int, sceGxmSetDefaultRegionClipAndViewport) {
    return unimplemented("sceGxmSetDefaultRegionClipAndViewport");
}

EXPORT(int, sceGxmSetDeferredContextFragmentBuffer) {
    return unimplemented("sceGxmSetDeferredContextFragmentBuffer");
}

EXPORT(int, sceGxmSetDeferredContextVdmBuffer) {
    return unimplemented("sceGxmSetDeferredContextVdmBuffer");
}

EXPORT(int, sceGxmSetDeferredContextVertexBuffer) {
    return unimplemented("sceGxmSetDeferredContextVertexBuffer");
}

EXPORT(int, sceGxmSetFragmentDefaultUniformBuffer) {
    return unimplemented("sceGxmSetFragmentDefaultUniformBuffer");
}

EXPORT(void, sceGxmSetFragmentProgram, SceGxmContext *context, const SceGxmFragmentProgram *fragmentProgram) {
    assert(context != nullptr);
    assert(fragmentProgram != nullptr);

    const SharedGLObject program = get_program(*context, *fragmentProgram);
    
    glUseProgram(program->get());
    glColorMask(fragmentProgram->color_mask_red, fragmentProgram->color_mask_green, fragmentProgram->color_mask_blue, fragmentProgram->color_mask_alpha);
    if (fragmentProgram->blend_enabled) {
        glEnable(GL_BLEND);
        glBlendEquationSeparate(fragmentProgram->color_func, fragmentProgram->alpha_func);
        glBlendFuncSeparate(fragmentProgram->color_src, fragmentProgram->color_dst, fragmentProgram->alpha_src, fragmentProgram->alpha_dst);
    } else {
        glDisable(GL_BLEND);
    }
}

EXPORT(int, sceGxmSetFragmentTexture, SceGxmContext *context, unsigned int textureIndex, const emu::SceGxmTexture *texture) {
    assert(context != nullptr);
    assert(texture != nullptr);
	
    glActiveTexture((GLenum)(GL_TEXTURE0 + textureIndex));
    glBindTexture(GL_TEXTURE_2D, context->texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);

    if (texture->format == SCE_GXM_TEXTURE_FORMAT_P8_ABGR) {
        glPixelTransferi(GL_MAP_COLOR, GL_TRUE);
        GLfloat map[4][256];
        const uint8_t(*const src)[4] = static_cast<uint8_t(*)[4]>(texture->palette.get(host.mem));
        for (size_t i = 0; i < 256; ++i) {
            map[0][i] = src[i][0] / 255.0f;
            map[1][i] = src[i][1] / 255.0f;
            map[2][i] = src[i][2] / 255.0f;
            map[3][i] = src[i][3] / 255.0f;
        }
        glPixelMapfv(GL_PIXEL_MAP_I_TO_R, 256, map[0]);
        glPixelMapfv(GL_PIXEL_MAP_I_TO_G, 256, map[1]);
        glPixelMapfv(GL_PIXEL_MAP_I_TO_B, 256, map[2]);
        glPixelMapfv(GL_PIXEL_MAP_I_TO_A, 256, map[3]);
    }

    const void *const pixels = texture->data.get(host.mem);
    const GLenum internal_format = translate_internal_format(texture->format);
    const GLenum format = translate_format(texture->format);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, (texture->width + 7) & ~7);
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, texture->width, texture->height, 0, format, GL_UNSIGNED_BYTE, pixels);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glPixelTransferi(GL_MAP_COLOR, GL_FALSE);

    return 0;
}

EXPORT(int, sceGxmSetFragmentUniformBuffer) {
    return unimplemented("sceGxmSetFragmentUniformBuffer");
}

EXPORT(int, sceGxmSetFrontDepthBias) {
    return unimplemented("sceGxmSetFrontDepthBias");
}

EXPORT(int, sceGxmSetFrontDepthFunc) {
    return unimplemented("sceGxmSetFrontDepthFunc");
}

EXPORT(int, sceGxmSetFrontDepthWriteEnable) {
    return unimplemented("sceGxmSetFrontDepthWriteEnable");
}

EXPORT(int, sceGxmSetFrontFragmentProgramEnable) {
    return unimplemented("sceGxmSetFrontFragmentProgramEnable");
}

EXPORT(int, sceGxmSetFrontLineFillLastPixelEnable) {
    return unimplemented("sceGxmSetFrontLineFillLastPixelEnable");
}

EXPORT(int, sceGxmSetFrontPointLineWidth) {
    return unimplemented("sceGxmSetFrontPointLineWidth");
}

EXPORT(int, sceGxmSetFrontPolygonMode) {
    return unimplemented("sceGxmSetFrontPolygonMode");
}

EXPORT(int, sceGxmSetFrontStencilFunc) {
    return unimplemented("sceGxmSetFrontStencilFunc");
}

EXPORT(int, sceGxmSetFrontStencilRef) {
    return unimplemented("sceGxmSetFrontStencilRef");
}

EXPORT(int, sceGxmSetFrontVisibilityTestEnable) {
    return unimplemented("sceGxmSetFrontVisibilityTestEnable");
}

EXPORT(int, sceGxmSetFrontVisibilityTestIndex) {
    return unimplemented("sceGxmSetFrontVisibilityTestIndex");
}

EXPORT(int, sceGxmSetFrontVisibilityTestOp) {
    return unimplemented("sceGxmSetFrontVisibilityTestOp");
}

EXPORT(int, sceGxmSetPrecomputedFragmentState) {
    return unimplemented("sceGxmSetPrecomputedFragmentState");
}

EXPORT(int, sceGxmSetPrecomputedVertexState) {
    return unimplemented("sceGxmSetPrecomputedVertexState");
}

EXPORT(int, sceGxmSetRegionClip) {
    return unimplemented("sceGxmSetRegionClip");
}

EXPORT(int, sceGxmSetTwoSidedEnable) {
    return unimplemented("sceGxmSetTwoSidedEnable");
}

EXPORT(int, sceGxmSetUniformDataF, void *uniformBuffer, const SceGxmProgramParameter *parameter, unsigned int componentOffset, unsigned int componentCount, const float *sourceData) {
    assert(uniformBuffer != nullptr);
    assert(parameter != nullptr);
    assert(componentOffset == 0);
    assert(componentCount > 0);
    assert(sourceData != nullptr);

    const char *const name = reinterpret_cast<const char *>(parameter) + parameter->name_offset;

    GLint program = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &program);
    assert(program != 0);

    const GLint location = glGetUniformLocation(program, name);
    if (location < 0) {
        // Happens when shaders can't be loaded, as dummy shaders do not have uniforms.
        return SCE_GXM_ERROR_INVALID_VALUE;
    }

    switch (componentCount) {
    case 4:
        glUniform4fv(location, 1, sourceData);
        break;

    case 16:
        glUniformMatrix4fv(location, 1, GL_FALSE, sourceData);
        break;

    default:
        assert(!"Unhandled component count.");
        break;
    }

    return 0;
}

EXPORT(int, sceGxmSetUserMarker) {
    return unimplemented("sceGxmSetUserMarker");
}

EXPORT(int, sceGxmSetValidationEnable) {
    return unimplemented("sceGxmSetValidationEnable");
}

EXPORT(int, sceGxmSetVertexDefaultUniformBuffer) {
    return unimplemented("sceGxmSetVertexDefaultUniformBuffer");
}

EXPORT(void, sceGxmSetVertexProgram, SceGxmContext *context, const SceGxmVertexProgram *vertexProgram) {
    assert(context != nullptr);
    assert(vertexProgram != nullptr);

    context->vertex_program = vertexProgram;
}

EXPORT(int, sceGxmSetVertexStream, SceGxmContext *context, unsigned int streamIndex, const uint8_t *streamData) {
    assert(context != nullptr);
    assert(streamData != nullptr);

    for (const emu::SceGxmVertexAttribute &attribute : context->vertex_program->attributes) {
        if (attribute.streamIndex != streamIndex) {
            continue;
        }

        const SceGxmVertexStream &stream = context->vertex_program->streams[attribute.streamIndex];

        const GLenum type = attribute_format_to_gl_type(static_cast<SceGxmAttributeFormat>(attribute.format));
        const GLboolean normalised = attribute_format_normalised(static_cast<SceGxmAttributeFormat>(attribute.format)) ? GL_TRUE : GL_FALSE;
        const GLvoid *const pointer = streamData + attribute.offset;
        glVertexAttribPointer(attribute.regIndex, attribute.componentCount, type, normalised, stream.stride, pointer);

        glEnableVertexAttribArray(attribute.regIndex); // TODO Disable.
    }

    return 0;
}

EXPORT(int, sceGxmSetVertexTexture) {
    return unimplemented("sceGxmSetVertexTexture");
}

EXPORT(int, sceGxmSetVertexUniformBuffer) {
    return unimplemented("sceGxmSetVertexUniformBuffer");
}

EXPORT(int, sceGxmSetViewport) {
    return unimplemented("sceGxmSetViewport");
}

EXPORT(int, sceGxmSetViewportEnable) {
    return unimplemented("sceGxmSetViewportEnable");
}

EXPORT(int, sceGxmSetVisibilityBuffer) {
    return unimplemented("sceGxmSetVisibilityBuffer");
}

EXPORT(int, sceGxmSetWBufferEnable) {
    return unimplemented("sceGxmSetWBufferEnable");
}

EXPORT(int, sceGxmSetWClampEnable) {
    return unimplemented("sceGxmSetWClampEnable");
}

EXPORT(int, sceGxmSetWClampValue) {
    return unimplemented("sceGxmSetWClampValue");
}

EXPORT(int, sceGxmSetWarningEnabled) {
    return unimplemented("sceGxmSetWarningEnabled");
}

EXPORT(int, sceGxmSetYuvProfile) {
    return unimplemented("sceGxmSetYuvProfile");
}

EXPORT(int, sceGxmShaderPatcherAddRefFragmentProgram, SceGxmShaderPatcher *shaderPatcher, SceGxmFragmentProgram *fragmentProgram) {
    assert(shaderPatcher != nullptr);
    assert(fragmentProgram != nullptr);
    
    ++fragmentProgram->reference_count;
    
    return 0;
}

EXPORT(int, sceGxmShaderPatcherAddRefVertexProgram, SceGxmShaderPatcher *shaderPatcher, SceGxmVertexProgram *vertexProgram) {
    assert(shaderPatcher != nullptr);
    assert(vertexProgram != nullptr);
    
    ++vertexProgram->reference_count;
    
    return 0;
}

EXPORT(int, sceGxmShaderPatcherCreate, const emu::SceGxmShaderPatcherParams *params, Ptr<SceGxmShaderPatcher> *shaderPatcher) {
    assert(params != nullptr);
    assert(shaderPatcher != nullptr);

    *shaderPatcher = alloc<SceGxmShaderPatcher>(host.mem, __FUNCTION__);
    assert(*shaderPatcher);
    if (!*shaderPatcher) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    return 0;
}

EXPORT(int, sceGxmShaderPatcherCreateFragmentProgram, SceGxmShaderPatcher *shaderPatcher, const SceGxmRegisteredProgram *programId, SceGxmOutputRegisterFormat outputFormat, SceGxmMultisampleMode multisampleMode, const emu::SceGxmBlendInfo *blendInfo, Ptr<const SceGxmProgram> vertexProgram, Ptr<SceGxmFragmentProgram> *fragmentProgram) {
    MemState &mem = host.mem;
    assert(shaderPatcher != nullptr);
    assert(programId != nullptr);
    assert(outputFormat == SCE_GXM_OUTPUT_REGISTER_FORMAT_UCHAR4);
    assert(multisampleMode == SCE_GXM_MULTISAMPLE_NONE);
    assert(vertexProgram);
    assert(fragmentProgram != nullptr);
    
    static const emu::SceGxmBlendInfo default_blend_info = {
        SCE_GXM_COLOR_MASK_ALL,
        SCE_GXM_BLEND_FUNC_NONE,
        SCE_GXM_BLEND_FUNC_NONE,
        SCE_GXM_BLEND_FACTOR_ONE,
        SCE_GXM_BLEND_FACTOR_ZERO,
        SCE_GXM_BLEND_FACTOR_ONE,
        SCE_GXM_BLEND_FACTOR_ZERO
    };
    const FragmentProgramCacheKey key = {
        *programId,
        (blendInfo != nullptr) ? *blendInfo : default_blend_info,
        vertexProgram
    };
    FragmentProgramCache::const_iterator cached = shaderPatcher->fragment_program_cache.find(key);
    if (cached != shaderPatcher->fragment_program_cache.end()) {
        ++cached->second.get(mem)->reference_count;
        *fragmentProgram = cached->second;
        return 0;
    }
    
    *fragmentProgram = alloc<SceGxmFragmentProgram>(mem, __FUNCTION__);
    assert(*fragmentProgram);
    if (!*fragmentProgram) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }
    
    SceGxmFragmentProgram *const fp = fragmentProgram->get(mem);
    fp->fragment_glsl = get_fragment_glsl(*shaderPatcher, *programId->program.get(mem), host.base_path.c_str());
    fp->vertex_glsl = get_vertex_glsl(*shaderPatcher, *vertexProgram.get(mem), host.base_path.c_str());
    fp->attribute_locations = attribute_locations(*vertexProgram.get(mem));

    // Translate blending.
    if (blendInfo != nullptr) {
        fp->color_mask_red = ((blendInfo->colorMask & SCE_GXM_COLOR_MASK_R) != 0) ? GL_TRUE : GL_FALSE;
        fp->color_mask_green = ((blendInfo->colorMask & SCE_GXM_COLOR_MASK_G) != 0) ? GL_TRUE : GL_FALSE;
        fp->color_mask_blue = ((blendInfo->colorMask & SCE_GXM_COLOR_MASK_B) != 0) ? GL_TRUE : GL_FALSE;
        fp->color_mask_alpha = ((blendInfo->colorMask & SCE_GXM_COLOR_MASK_A) != 0) ? GL_TRUE : GL_FALSE;
        fp->blend_enabled = true;
        fp->color_func = translate_blend_func(blendInfo->colorFunc);
        fp->alpha_func = translate_blend_func(blendInfo->alphaFunc);
        fp->color_src = translate_blend_factor(blendInfo->colorSrc);
        fp->color_dst = translate_blend_factor(blendInfo->colorDst);
        fp->alpha_src = translate_blend_factor(blendInfo->alphaSrc);
        fp->alpha_dst = translate_blend_factor(blendInfo->alphaDst);
    }

    shaderPatcher->fragment_program_cache.emplace(key, *fragmentProgram);
    
    return 0;
}

EXPORT(int, sceGxmShaderPatcherCreateMaskUpdateFragmentProgram) {
    return unimplemented("sceGxmShaderPatcherCreateMaskUpdateFragmentProgram");
}

EXPORT(int, sceGxmShaderPatcherCreateVertexProgram, SceGxmShaderPatcher *shaderPatcher, const SceGxmRegisteredProgram *programId, const emu::SceGxmVertexAttribute *attributes, unsigned int attributeCount, const SceGxmVertexStream *streams, unsigned int streamCount, Ptr<SceGxmVertexProgram> *vertexProgram) {
    MemState &mem = host.mem;
    assert(shaderPatcher != nullptr);
    assert(programId != nullptr);
    assert(attributes != nullptr);
    assert(attributeCount > 0);
    assert(streams != nullptr);
    assert(streamCount > 0);
    assert(vertexProgram != nullptr);

    *vertexProgram = alloc<SceGxmVertexProgram>(mem, __FUNCTION__);
    assert(*vertexProgram);
    if (!*vertexProgram) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    SceGxmVertexProgram *const vp = vertexProgram->get(mem);
    vp->streams.insert(vp->streams.end(), &streams[0], &streams[streamCount]);
    vp->attributes.insert(vp->attributes.end(), &attributes[0], &attributes[attributeCount]);

    return 0;
}

EXPORT(int, sceGxmShaderPatcherDestroy, Ptr<SceGxmShaderPatcher> shaderPatcher) {
    assert(shaderPatcher);

    free(host.mem, shaderPatcher);

    return 0;
}

EXPORT(int, sceGxmShaderPatcherForceUnregisterProgram) {
    return unimplemented("sceGxmShaderPatcherForceUnregisterProgram");
}

EXPORT(int, sceGxmShaderPatcherGetBufferMemAllocated) {
    return unimplemented("sceGxmShaderPatcherGetBufferMemAllocated");
}

EXPORT(int, sceGxmShaderPatcherGetFragmentProgramRefCount) {
    return unimplemented("sceGxmShaderPatcherGetFragmentProgramRefCount");
}

EXPORT(int, sceGxmShaderPatcherGetFragmentUsseMemAllocated) {
    return unimplemented("sceGxmShaderPatcherGetFragmentUsseMemAllocated");
}

EXPORT(int, sceGxmShaderPatcherGetHostMemAllocated) {
    return unimplemented("sceGxmShaderPatcherGetHostMemAllocated");
}

EXPORT(Ptr<const SceGxmProgram>, sceGxmShaderPatcherGetProgramFromId, emu::SceGxmShaderPatcherId programId) {
    if (!programId) {
        return Ptr<const SceGxmProgram>();
    }
    
    return programId.get(host.mem)->program;
}

EXPORT(int, sceGxmShaderPatcherGetUserData) {
    return unimplemented("sceGxmShaderPatcherGetUserData");
}

EXPORT(int, sceGxmShaderPatcherGetVertexProgramRefCount) {
    return unimplemented("sceGxmShaderPatcherGetVertexProgramRefCount");
}

EXPORT(int, sceGxmShaderPatcherGetVertexUsseMemAllocated) {
    return unimplemented("sceGxmShaderPatcherGetVertexUsseMemAllocated");
}

EXPORT(int, sceGxmShaderPatcherRegisterProgram, SceGxmShaderPatcher *shaderPatcher, Ptr<const SceGxmProgram> programHeader, emu::SceGxmShaderPatcherId *programId) {
    assert(shaderPatcher != nullptr);
    assert(programHeader);
    assert(programId != nullptr);

    *programId = alloc<SceGxmRegisteredProgram>(host.mem, __FUNCTION__);
    assert(*programId);
    if (!*programId) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    SceGxmRegisteredProgram *const rp = programId->get(host.mem);
    rp->program = programHeader;

    return 0;
}

EXPORT(int, sceGxmShaderPatcherReleaseFragmentProgram, SceGxmShaderPatcher *shaderPatcher, Ptr<SceGxmFragmentProgram> fragmentProgram) {
    assert(shaderPatcher != nullptr);
    assert(fragmentProgram);

    SceGxmFragmentProgram *const fp = fragmentProgram.get(host.mem);
    --fp->reference_count;
    if (fp->reference_count == 0) {
        for (FragmentProgramCache::const_iterator it = shaderPatcher->fragment_program_cache.begin(); it != shaderPatcher->fragment_program_cache.end(); ++it) {
            if (it->second == fragmentProgram) {
                shaderPatcher->fragment_program_cache.erase(it);
                break;
            }
        }
        free(host.mem, fragmentProgram);
    }

    return 0;
}

EXPORT(int, sceGxmShaderPatcherReleaseVertexProgram, SceGxmShaderPatcher *shaderPatcher, Ptr<SceGxmVertexProgram> vertexProgram) {
    assert(shaderPatcher != nullptr);
    assert(vertexProgram);

    SceGxmVertexProgram *const vp = vertexProgram.get(host.mem);
    --vp->reference_count;
    if (vp->reference_count == 0) {
        free(host.mem, vertexProgram);
    }

    return 0;
}

EXPORT(int, sceGxmShaderPatcherSetAuxiliarySurface) {
    return unimplemented("sceGxmShaderPatcherSetAuxiliarySurface");
}

EXPORT(int, sceGxmShaderPatcherSetUserData) {
    return unimplemented("sceGxmShaderPatcherSetUserData");
}

EXPORT(int, sceGxmShaderPatcherUnregisterProgram, SceGxmShaderPatcher *shaderPatcher, emu::SceGxmShaderPatcherId programId) {
    assert(shaderPatcher != nullptr);
    assert(programId);

    SceGxmRegisteredProgram *const rp = programId.get(host.mem);
    rp->program.reset();

    free(host.mem, programId);

    return 0;
}

EXPORT(int, sceGxmSyncObjectCreate, Ptr<SceGxmSyncObject> *syncObject) {
    assert(syncObject != nullptr);

    *syncObject = alloc<SceGxmSyncObject>(host.mem, __FUNCTION__);
    if (!*syncObject) {
        return SCE_GXM_ERROR_OUT_OF_MEMORY;
    }

    return 0;
}

EXPORT(int, sceGxmSyncObjectDestroy, Ptr<SceGxmSyncObject> syncObject) {
    assert(syncObject);

    free(host.mem, syncObject);

    return 0;
}

EXPORT(int, sceGxmTerminate) {
    return 0;
}

EXPORT(int, sceGxmTextureGetData, const emu::SceGxmTexture *texture) {
    assert(texture != nullptr);

    return texture->data.address();
}

EXPORT(int, sceGxmTextureGetAnisoMode) {
    return unimplemented("sceGxmTextureGetAnisoMode");
}

EXPORT(int, sceGxmTextureGetFormat, const emu::SceGxmTexture *texture) {
    assert(texture != nullptr);

    return texture->format;
}

EXPORT(int, sceGxmTextureGetGammaMode) {
    return unimplemented("sceGxmTextureGetGammaMode");
}

EXPORT(int, sceGxmTextureGetHeight, const emu::SceGxmTexture *texture) {
    assert(texture != nullptr);

    return texture->height;
}

EXPORT(int, sceGxmTextureGetLodBias) {
    return unimplemented("sceGxmTextureGetLodBias");
}

EXPORT(int, sceGxmTextureGetLodMin) {
    return unimplemented("sceGxmTextureGetLodMin");
}

EXPORT(int, sceGxmTextureGetMagFilter) {
    return unimplemented("sceGxmTextureGetMagFilter");
}

EXPORT(int, sceGxmTextureGetMinFilter) {
    return unimplemented("sceGxmTextureGetMinFilter");
}

EXPORT(int, sceGxmTextureGetMipFilter) {
    return unimplemented("sceGxmTextureGetMipFilter");
}

EXPORT(int, sceGxmTextureGetMipmapCount) {
    return unimplemented("sceGxmTextureGetMipmapCount");
}

EXPORT(int, sceGxmTextureGetNormalizeMode) {
    return unimplemented("sceGxmTextureGetNormalizeMode");
}

EXPORT(Ptr<void>, sceGxmTextureGetPalette, const emu::SceGxmTexture *texture) {
    assert(texture != nullptr);
    assert(texture->format == SCE_GXM_TEXTURE_FORMAT_P8_ABGR);

    return texture->palette;
}

EXPORT(int, sceGxmTextureGetStride) {
    return unimplemented("sceGxmTextureGetStride");
}

EXPORT(int, sceGxmTextureGetType) {
    return unimplemented("sceGxmTextureGetType");
}

EXPORT(int, sceGxmTextureGetUAddrMode) {
    return unimplemented("sceGxmTextureGetUAddrMode");
}

EXPORT(int, sceGxmTextureGetVAddrMode) {
    return unimplemented("sceGxmTextureGetVAddrMode");
}

EXPORT(int, sceGxmTextureGetWidth, const emu::SceGxmTexture *texture) {
    assert(texture != nullptr);

    return texture->width;
}

EXPORT(int, sceGxmTextureInitCube) {
    return unimplemented("sceGxmTextureInitCube");
}

EXPORT(int, sceGxmTextureInitCubeArbitrary) {
    return unimplemented("sceGxmTextureInitCubeArbitrary");
}

EXPORT(int, sceGxmTextureInitLinear, emu::SceGxmTexture *texture, Ptr<const void> data, SceGxmTextureFormat texFormat, unsigned int width, unsigned int height, unsigned int mipCount) {
    assert(texture != nullptr);
    assert(data);
    assert((texFormat == SCE_GXM_TEXTURE_FORMAT_U8U8U8U8_ABGR) || (texFormat == SCE_GXM_TEXTURE_FORMAT_U8_R111) || (texFormat == SCE_GXM_TEXTURE_FORMAT_P8_ABGR));
    assert(width > 0);
    assert(height > 0);

    texture->format = texFormat;
    texture->width = width;
    texture->height = height;
    texture->data = data;
    texture->palette = Ptr<void>();
    // TODO Support mip-mapping.

    return 0;
}

EXPORT(int, sceGxmTextureInitLinearStrided) {
    return unimplemented("sceGxmTextureInitLinearStrided");
}

EXPORT(int, sceGxmTextureInitSwizzled) {
    return unimplemented("sceGxmTextureInitSwizzled");
}

EXPORT(int, sceGxmTextureInitSwizzledArbitrary) {
    return unimplemented("sceGxmTextureInitSwizzledArbitrary");
}

EXPORT(int, sceGxmTextureInitTiled) {
    return unimplemented("sceGxmTextureInitTiled");
}

EXPORT(int, sceGxmTextureSetData, emu::SceGxmTexture *texture, Ptr<const void> data) {
    assert(texture != nullptr);
    assert(data);
    
    texture->data = data;
    return 0;
}

EXPORT(int, sceGxmTextureSetAnisoMode) {
    return unimplemented("sceGxmTextureSetAnisoMode");
}

EXPORT(int, sceGxmTextureSetFormat) {
    return unimplemented("sceGxmTextureSetFormat");
}

EXPORT(int, sceGxmTextureSetGammaMode) {
    return unimplemented("sceGxmTextureSetGammaMode");
}

EXPORT(int, sceGxmTextureSetHeight, emu::SceGxmTexture *texture, unsigned int height) {
    assert(texture != nullptr);
    
    texture->height = height;
    return 0;
}

EXPORT(int, sceGxmTextureSetLodBias) {
    return unimplemented("sceGxmTextureSetLodBias");
}

EXPORT(int, sceGxmTextureSetLodMin) {
    return unimplemented("sceGxmTextureSetLodMin");
}

EXPORT(int, sceGxmTextureSetMagFilter) {
    return unimplemented("sceGxmTextureSetMagFilter");
}

EXPORT(int, sceGxmTextureSetMinFilter) {
    return unimplemented("sceGxmTextureSetMinFilter");
}

EXPORT(int, sceGxmTextureSetMipFilter) {
    return unimplemented("sceGxmTextureSetMipFilter");
}

EXPORT(int, sceGxmTextureSetMipmapCount) {
    return unimplemented("sceGxmTextureSetMipmapCount");
}

EXPORT(int, sceGxmTextureSetNormalizeMode) {
    return unimplemented("sceGxmTextureSetNormalizeMode");
}

EXPORT(int, sceGxmTextureSetPalette, emu::SceGxmTexture *texture, Ptr<void> paletteData) {
    assert(texture != nullptr);
    assert(texture->format == SCE_GXM_TEXTURE_FORMAT_P8_ABGR);
    assert(paletteData);

    texture->palette = paletteData;

    return 0;
}

EXPORT(int, sceGxmTextureSetStride) {
    return unimplemented("sceGxmTextureSetStride");
}

EXPORT(int, sceGxmTextureSetUAddrMode) {
    return unimplemented("sceGxmTextureSetUAddrMode");
}

EXPORT(int, sceGxmTextureSetVAddrMode) {
    return unimplemented("sceGxmTextureSetVAddrMode");
}

EXPORT(int, sceGxmTextureSetWidth, emu::SceGxmTexture *texture, unsigned int width) {
    assert(texture != nullptr);
    
    texture->width = width;
    return 0;
}

EXPORT(int, sceGxmTextureValidate) {
    return unimplemented("sceGxmTextureValidate");
}

EXPORT(int, sceGxmTransferCopy) {
    return unimplemented("sceGxmTransferCopy");
}

EXPORT(int, sceGxmTransferDownscale) {
    return unimplemented("sceGxmTransferDownscale");
}

EXPORT(int, sceGxmTransferFill) {
    return unimplemented("sceGxmTransferFill");
}

EXPORT(int, sceGxmTransferFinish) {
    return unimplemented("sceGxmTransferFinish");
}

EXPORT(int, sceGxmUnmapFragmentUsseMemory, void *base) {
    assert(base != nullptr);

    return 0;
}

EXPORT(int, sceGxmUnmapMemory, void *base) {
    assert(base != nullptr);

    return 0;
}

EXPORT(int, sceGxmUnmapVertexUsseMemory, void *base) {
    assert(base != nullptr);

    return 0;
}

EXPORT(int, sceGxmVertexFence) {
    return unimplemented("sceGxmVertexFence");
}

EXPORT(int, sceGxmVertexProgramGetProgram) {
    return unimplemented("sceGxmVertexProgramGetProgram");
}

EXPORT(int, sceGxmWaitEvent) {
    return unimplemented("sceGxmWaitEvent");
}

BRIDGE_IMPL(sceGxmAddRazorGpuCaptureBuffer)
BRIDGE_IMPL(sceGxmBeginCommandList)
BRIDGE_IMPL(sceGxmBeginScene)
BRIDGE_IMPL(sceGxmBeginSceneEx)
BRIDGE_IMPL(sceGxmColorSurfaceGetClip)
BRIDGE_IMPL(sceGxmColorSurfaceGetData)
BRIDGE_IMPL(sceGxmColorSurfaceGetDitherMode)
BRIDGE_IMPL(sceGxmColorSurfaceGetFormat)
BRIDGE_IMPL(sceGxmColorSurfaceGetGammaMode)
BRIDGE_IMPL(sceGxmColorSurfaceGetScaleMode)
BRIDGE_IMPL(sceGxmColorSurfaceGetStrideInPixels)
BRIDGE_IMPL(sceGxmColorSurfaceGetType)
BRIDGE_IMPL(sceGxmColorSurfaceInit)
BRIDGE_IMPL(sceGxmColorSurfaceInitDisabled)
BRIDGE_IMPL(sceGxmColorSurfaceIsEnabled)
BRIDGE_IMPL(sceGxmColorSurfaceSetClip)
BRIDGE_IMPL(sceGxmColorSurfaceSetData)
BRIDGE_IMPL(sceGxmColorSurfaceSetDitherMode)
BRIDGE_IMPL(sceGxmColorSurfaceSetFormat)
BRIDGE_IMPL(sceGxmColorSurfaceSetGammaMode)
BRIDGE_IMPL(sceGxmColorSurfaceSetScaleMode)
BRIDGE_IMPL(sceGxmCreateContext)
BRIDGE_IMPL(sceGxmCreateDeferredContext)
BRIDGE_IMPL(sceGxmCreateRenderTarget)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetBackgroundDepth)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetBackgroundMask)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetBackgroundStencil)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetForceLoadMode)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetForceStoreMode)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetFormat)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceGetStrideInSamples)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceInit)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceInitDisabled)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceIsEnabled)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceSetBackgroundDepth)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceSetBackgroundMask)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceSetBackgroundStencil)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceSetForceLoadMode)
BRIDGE_IMPL(sceGxmDepthStencilSurfaceSetForceStoreMode)
BRIDGE_IMPL(sceGxmDestroyContext)
BRIDGE_IMPL(sceGxmDestroyDeferredContext)
BRIDGE_IMPL(sceGxmDestroyRenderTarget)
BRIDGE_IMPL(sceGxmDisplayQueueAddEntry)
BRIDGE_IMPL(sceGxmDisplayQueueFinish)
BRIDGE_IMPL(sceGxmDraw)
BRIDGE_IMPL(sceGxmDrawInstanced)
BRIDGE_IMPL(sceGxmDrawPrecomputed)
BRIDGE_IMPL(sceGxmEndCommandList)
BRIDGE_IMPL(sceGxmEndScene)
BRIDGE_IMPL(sceGxmExecuteCommandList)
BRIDGE_IMPL(sceGxmFinish)
BRIDGE_IMPL(sceGxmFragmentProgramGetPassType)
BRIDGE_IMPL(sceGxmFragmentProgramGetProgram)
BRIDGE_IMPL(sceGxmFragmentProgramIsEnabled)
BRIDGE_IMPL(sceGxmGetContextType)
BRIDGE_IMPL(sceGxmGetDeferredContextFragmentBuffer)
BRIDGE_IMPL(sceGxmGetDeferredContextVdmBuffer)
BRIDGE_IMPL(sceGxmGetDeferredContextVertexBuffer)
BRIDGE_IMPL(sceGxmGetNotificationRegion)
BRIDGE_IMPL(sceGxmGetParameterBufferThreshold)
BRIDGE_IMPL(sceGxmGetPrecomputedDrawSize)
BRIDGE_IMPL(sceGxmGetPrecomputedFragmentStateSize)
BRIDGE_IMPL(sceGxmGetPrecomputedVertexStateSize)
BRIDGE_IMPL(sceGxmGetRenderTargetMemSizes)
BRIDGE_IMPL(sceGxmInitialize)
BRIDGE_IMPL(sceGxmIsDebugVersion)
BRIDGE_IMPL(sceGxmMapFragmentUsseMemory)
BRIDGE_IMPL(sceGxmMapMemory)
BRIDGE_IMPL(sceGxmMapVertexUsseMemory)
BRIDGE_IMPL(sceGxmMidSceneFlush)
BRIDGE_IMPL(sceGxmNotificationWait)
BRIDGE_IMPL(sceGxmPadHeartbeat)
BRIDGE_IMPL(sceGxmPadTriggerGpuPaTrace)
BRIDGE_IMPL(sceGxmPopUserMarker)
BRIDGE_IMPL(sceGxmPrecomputedDrawInit)
BRIDGE_IMPL(sceGxmPrecomputedDrawSetAllVertexStreams)
BRIDGE_IMPL(sceGxmPrecomputedDrawSetParams)
BRIDGE_IMPL(sceGxmPrecomputedDrawSetParamsInstanced)
BRIDGE_IMPL(sceGxmPrecomputedDrawSetVertexStream)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateGetDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateInit)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateSetAllAuxiliarySurfaces)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateSetAllTextures)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateSetAllUniformBuffers)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateSetDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateSetTexture)
BRIDGE_IMPL(sceGxmPrecomputedFragmentStateSetUniformBuffer)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateGetDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateInit)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateSetAllTextures)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateSetAllUniformBuffers)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateSetDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateSetTexture)
BRIDGE_IMPL(sceGxmPrecomputedVertexStateSetUniformBuffer)
BRIDGE_IMPL(sceGxmProgramCheck)
BRIDGE_IMPL(sceGxmProgramFindParameterByName)
BRIDGE_IMPL(sceGxmProgramFindParameterBySemantic)
BRIDGE_IMPL(sceGxmProgramGetDefaultUniformBufferSize)
BRIDGE_IMPL(sceGxmProgramGetFragmentProgramInputs)
BRIDGE_IMPL(sceGxmProgramGetOutputRegisterFormat)
BRIDGE_IMPL(sceGxmProgramGetParameter)
BRIDGE_IMPL(sceGxmProgramGetParameterCount)
BRIDGE_IMPL(sceGxmProgramGetSize)
BRIDGE_IMPL(sceGxmProgramGetType)
BRIDGE_IMPL(sceGxmProgramGetVertexProgramOutputs)
BRIDGE_IMPL(sceGxmProgramIsDepthReplaceUsed)
BRIDGE_IMPL(sceGxmProgramIsDiscardUsed)
BRIDGE_IMPL(sceGxmProgramIsEquivalent)
BRIDGE_IMPL(sceGxmProgramIsFragColorUsed)
BRIDGE_IMPL(sceGxmProgramIsNativeColorUsed)
BRIDGE_IMPL(sceGxmProgramIsSpriteCoordUsed)
BRIDGE_IMPL(sceGxmProgramParameterGetArraySize)
BRIDGE_IMPL(sceGxmProgramParameterGetCategory)
BRIDGE_IMPL(sceGxmProgramParameterGetComponentCount)
BRIDGE_IMPL(sceGxmProgramParameterGetContainerIndex)
BRIDGE_IMPL(sceGxmProgramParameterGetIndex)
BRIDGE_IMPL(sceGxmProgramParameterGetName)
BRIDGE_IMPL(sceGxmProgramParameterGetResourceIndex)
BRIDGE_IMPL(sceGxmProgramParameterGetSemantic)
BRIDGE_IMPL(sceGxmProgramParameterGetSemanticIndex)
BRIDGE_IMPL(sceGxmProgramParameterGetType)
BRIDGE_IMPL(sceGxmProgramParameterIsRegFormat)
BRIDGE_IMPL(sceGxmProgramParameterIsSamplerCube)
BRIDGE_IMPL(sceGxmPushUserMarker)
BRIDGE_IMPL(sceGxmRemoveRazorGpuCaptureBuffer)
BRIDGE_IMPL(sceGxmRenderTargetGetDriverMemBlock)
BRIDGE_IMPL(sceGxmRenderTargetGetHostMem)
BRIDGE_IMPL(sceGxmReserveFragmentDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmReserveVertexDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmSetAuxiliarySurface)
BRIDGE_IMPL(sceGxmSetBackDepthBias)
BRIDGE_IMPL(sceGxmSetBackDepthFunc)
BRIDGE_IMPL(sceGxmSetBackDepthWriteEnable)
BRIDGE_IMPL(sceGxmSetBackFragmentProgramEnable)
BRIDGE_IMPL(sceGxmSetBackLineFillLastPixelEnable)
BRIDGE_IMPL(sceGxmSetBackPointLineWidth)
BRIDGE_IMPL(sceGxmSetBackPolygonMode)
BRIDGE_IMPL(sceGxmSetBackStencilFunc)
BRIDGE_IMPL(sceGxmSetBackStencilRef)
BRIDGE_IMPL(sceGxmSetBackVisibilityTestEnable)
BRIDGE_IMPL(sceGxmSetBackVisibilityTestIndex)
BRIDGE_IMPL(sceGxmSetBackVisibilityTestOp)
BRIDGE_IMPL(sceGxmSetCullMode)
BRIDGE_IMPL(sceGxmSetDefaultRegionClipAndViewport)
BRIDGE_IMPL(sceGxmSetDeferredContextFragmentBuffer)
BRIDGE_IMPL(sceGxmSetDeferredContextVdmBuffer)
BRIDGE_IMPL(sceGxmSetDeferredContextVertexBuffer)
BRIDGE_IMPL(sceGxmSetFragmentDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmSetFragmentProgram)
BRIDGE_IMPL(sceGxmSetFragmentTexture)
BRIDGE_IMPL(sceGxmSetFragmentUniformBuffer)
BRIDGE_IMPL(sceGxmSetFrontDepthBias)
BRIDGE_IMPL(sceGxmSetFrontDepthFunc)
BRIDGE_IMPL(sceGxmSetFrontDepthWriteEnable)
BRIDGE_IMPL(sceGxmSetFrontFragmentProgramEnable)
BRIDGE_IMPL(sceGxmSetFrontLineFillLastPixelEnable)
BRIDGE_IMPL(sceGxmSetFrontPointLineWidth)
BRIDGE_IMPL(sceGxmSetFrontPolygonMode)
BRIDGE_IMPL(sceGxmSetFrontStencilFunc)
BRIDGE_IMPL(sceGxmSetFrontStencilRef)
BRIDGE_IMPL(sceGxmSetFrontVisibilityTestEnable)
BRIDGE_IMPL(sceGxmSetFrontVisibilityTestIndex)
BRIDGE_IMPL(sceGxmSetFrontVisibilityTestOp)
BRIDGE_IMPL(sceGxmSetPrecomputedFragmentState)
BRIDGE_IMPL(sceGxmSetPrecomputedVertexState)
BRIDGE_IMPL(sceGxmSetRegionClip)
BRIDGE_IMPL(sceGxmSetTwoSidedEnable)
BRIDGE_IMPL(sceGxmSetUniformDataF)
BRIDGE_IMPL(sceGxmSetUserMarker)
BRIDGE_IMPL(sceGxmSetValidationEnable)
BRIDGE_IMPL(sceGxmSetVertexDefaultUniformBuffer)
BRIDGE_IMPL(sceGxmSetVertexProgram)
BRIDGE_IMPL(sceGxmSetVertexStream)
BRIDGE_IMPL(sceGxmSetVertexTexture)
BRIDGE_IMPL(sceGxmSetVertexUniformBuffer)
BRIDGE_IMPL(sceGxmSetViewport)
BRIDGE_IMPL(sceGxmSetViewportEnable)
BRIDGE_IMPL(sceGxmSetVisibilityBuffer)
BRIDGE_IMPL(sceGxmSetWBufferEnable)
BRIDGE_IMPL(sceGxmSetWClampEnable)
BRIDGE_IMPL(sceGxmSetWClampValue)
BRIDGE_IMPL(sceGxmSetWarningEnabled)
BRIDGE_IMPL(sceGxmSetYuvProfile)
BRIDGE_IMPL(sceGxmShaderPatcherAddRefFragmentProgram)
BRIDGE_IMPL(sceGxmShaderPatcherAddRefVertexProgram)
BRIDGE_IMPL(sceGxmShaderPatcherCreate)
BRIDGE_IMPL(sceGxmShaderPatcherCreateFragmentProgram)
BRIDGE_IMPL(sceGxmShaderPatcherCreateMaskUpdateFragmentProgram)
BRIDGE_IMPL(sceGxmShaderPatcherCreateVertexProgram)
BRIDGE_IMPL(sceGxmShaderPatcherDestroy)
BRIDGE_IMPL(sceGxmShaderPatcherForceUnregisterProgram)
BRIDGE_IMPL(sceGxmShaderPatcherGetBufferMemAllocated)
BRIDGE_IMPL(sceGxmShaderPatcherGetFragmentProgramRefCount)
BRIDGE_IMPL(sceGxmShaderPatcherGetFragmentUsseMemAllocated)
BRIDGE_IMPL(sceGxmShaderPatcherGetHostMemAllocated)
BRIDGE_IMPL(sceGxmShaderPatcherGetProgramFromId)
BRIDGE_IMPL(sceGxmShaderPatcherGetUserData)
BRIDGE_IMPL(sceGxmShaderPatcherGetVertexProgramRefCount)
BRIDGE_IMPL(sceGxmShaderPatcherGetVertexUsseMemAllocated)
BRIDGE_IMPL(sceGxmShaderPatcherRegisterProgram)
BRIDGE_IMPL(sceGxmShaderPatcherReleaseFragmentProgram)
BRIDGE_IMPL(sceGxmShaderPatcherReleaseVertexProgram)
BRIDGE_IMPL(sceGxmShaderPatcherSetAuxiliarySurface)
BRIDGE_IMPL(sceGxmShaderPatcherSetUserData)
BRIDGE_IMPL(sceGxmShaderPatcherUnregisterProgram)
BRIDGE_IMPL(sceGxmSyncObjectCreate)
BRIDGE_IMPL(sceGxmSyncObjectDestroy)
BRIDGE_IMPL(sceGxmTerminate)
BRIDGE_IMPL(sceGxmTextureGetAnisoMode)
BRIDGE_IMPL(sceGxmTextureGetData)
BRIDGE_IMPL(sceGxmTextureGetFormat)
BRIDGE_IMPL(sceGxmTextureGetGammaMode)
BRIDGE_IMPL(sceGxmTextureGetHeight)
BRIDGE_IMPL(sceGxmTextureGetLodBias)
BRIDGE_IMPL(sceGxmTextureGetLodMin)
BRIDGE_IMPL(sceGxmTextureGetMagFilter)
BRIDGE_IMPL(sceGxmTextureGetMinFilter)
BRIDGE_IMPL(sceGxmTextureGetMipFilter)
BRIDGE_IMPL(sceGxmTextureGetMipmapCount)
BRIDGE_IMPL(sceGxmTextureGetNormalizeMode)
BRIDGE_IMPL(sceGxmTextureGetPalette)
BRIDGE_IMPL(sceGxmTextureGetStride)
BRIDGE_IMPL(sceGxmTextureGetType)
BRIDGE_IMPL(sceGxmTextureGetUAddrMode)
BRIDGE_IMPL(sceGxmTextureGetVAddrMode)
BRIDGE_IMPL(sceGxmTextureGetWidth)
BRIDGE_IMPL(sceGxmTextureInitCube)
BRIDGE_IMPL(sceGxmTextureInitCubeArbitrary)
BRIDGE_IMPL(sceGxmTextureInitLinear)
BRIDGE_IMPL(sceGxmTextureInitLinearStrided)
BRIDGE_IMPL(sceGxmTextureInitSwizzled)
BRIDGE_IMPL(sceGxmTextureInitSwizzledArbitrary)
BRIDGE_IMPL(sceGxmTextureInitTiled)
BRIDGE_IMPL(sceGxmTextureSetAnisoMode)
BRIDGE_IMPL(sceGxmTextureSetData)
BRIDGE_IMPL(sceGxmTextureSetFormat)
BRIDGE_IMPL(sceGxmTextureSetGammaMode)
BRIDGE_IMPL(sceGxmTextureSetHeight)
BRIDGE_IMPL(sceGxmTextureSetLodBias)
BRIDGE_IMPL(sceGxmTextureSetLodMin)
BRIDGE_IMPL(sceGxmTextureSetMagFilter)
BRIDGE_IMPL(sceGxmTextureSetMinFilter)
BRIDGE_IMPL(sceGxmTextureSetMipFilter)
BRIDGE_IMPL(sceGxmTextureSetMipmapCount)
BRIDGE_IMPL(sceGxmTextureSetNormalizeMode)
BRIDGE_IMPL(sceGxmTextureSetPalette)
BRIDGE_IMPL(sceGxmTextureSetStride)
BRIDGE_IMPL(sceGxmTextureSetUAddrMode)
BRIDGE_IMPL(sceGxmTextureSetVAddrMode)
BRIDGE_IMPL(sceGxmTextureSetWidth)
BRIDGE_IMPL(sceGxmTextureValidate)
BRIDGE_IMPL(sceGxmTransferCopy)
BRIDGE_IMPL(sceGxmTransferDownscale)
BRIDGE_IMPL(sceGxmTransferFill)
BRIDGE_IMPL(sceGxmTransferFinish)
BRIDGE_IMPL(sceGxmUnmapFragmentUsseMemory)
BRIDGE_IMPL(sceGxmUnmapMemory)
BRIDGE_IMPL(sceGxmUnmapVertexUsseMemory)
BRIDGE_IMPL(sceGxmVertexFence)
BRIDGE_IMPL(sceGxmVertexProgramGetProgram)
BRIDGE_IMPL(sceGxmWaitEvent)
