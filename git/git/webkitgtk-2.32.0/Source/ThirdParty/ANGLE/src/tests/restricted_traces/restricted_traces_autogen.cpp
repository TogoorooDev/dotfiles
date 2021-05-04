// GENERATED FILE - DO NOT EDIT.
// Generated by gen_restricted_traces.py using data from restricted_traces.json
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// restricted_traces_autogen: Types and enumerations for trace tests.

#include "restricted_traces_autogen.h"

#include "common/PackedEnums.h"

#include "angry_birds_2_1500/angry_birds_2_1500_capture_context1.h"
#include "arena_of_valor/arena_of_valor_capture_context1.h"
#include "brawl_stars/brawl_stars_capture_context1.h"
#include "candy_crush_500/candy_crush_500_capture_context1.h"
#include "clash_of_clans/clash_of_clans_capture_context1.h"
#include "cod_mobile/cod_mobile_capture_context1.h"
#include "dragon_ball_legends/dragon_ball_legends_capture_context1.h"
#include "egypt_1500/egypt_1500_capture_context1.h"
#include "fate_grand_order/fate_grand_order_capture_context1.h"
#include "free_fire/free_fire_capture_context1.h"
#include "kartrider_rush/kartrider_rush_capture_context1.h"
#include "manhattan_10/manhattan_10_capture_context1.h"
#include "marvel_contest_of_champions/marvel_contest_of_champions_capture_context1.h"
#include "mobile_legends/mobile_legends_capture_context1.h"
#include "nba2k20_800/nba2k20_800_capture_context1.h"
#include "pubg_mobile_lite/pubg_mobile_lite_capture_context1.h"
#include "temple_run_300/temple_run_300_capture_context1.h"
#include "trex_200/trex_200_capture_context1.h"
#include "world_of_tanks_blitz/world_of_tanks_blitz_capture_context1.h"

namespace angle
{
namespace
{
constexpr angle::PackedEnumMap<RestrictedTraceID, TraceInfo> kTraceInfos = {
    {RestrictedTraceID::angry_birds_2_1500,
     {angry_birds_2_1500::kReplayFrameStart, angry_birds_2_1500::kReplayFrameEnd,
      angry_birds_2_1500::kReplayDrawSurfaceWidth, angry_birds_2_1500::kReplayDrawSurfaceHeight,
      "angry_birds_2_1500"}},
    {RestrictedTraceID::arena_of_valor,
     {arena_of_valor::kReplayFrameStart, arena_of_valor::kReplayFrameEnd,
      arena_of_valor::kReplayDrawSurfaceWidth, arena_of_valor::kReplayDrawSurfaceHeight,
      "arena_of_valor"}},
    {RestrictedTraceID::brawl_stars,
     {brawl_stars::kReplayFrameStart, brawl_stars::kReplayFrameEnd,
      brawl_stars::kReplayDrawSurfaceWidth, brawl_stars::kReplayDrawSurfaceHeight, "brawl_stars"}},
    {RestrictedTraceID::candy_crush_500,
     {candy_crush_500::kReplayFrameStart, candy_crush_500::kReplayFrameEnd,
      candy_crush_500::kReplayDrawSurfaceWidth, candy_crush_500::kReplayDrawSurfaceHeight,
      "candy_crush_500"}},
    {RestrictedTraceID::clash_of_clans,
     {clash_of_clans::kReplayFrameStart, clash_of_clans::kReplayFrameEnd,
      clash_of_clans::kReplayDrawSurfaceWidth, clash_of_clans::kReplayDrawSurfaceHeight,
      "clash_of_clans"}},
    {RestrictedTraceID::cod_mobile,
     {cod_mobile::kReplayFrameStart, cod_mobile::kReplayFrameEnd,
      cod_mobile::kReplayDrawSurfaceWidth, cod_mobile::kReplayDrawSurfaceHeight, "cod_mobile"}},
    {RestrictedTraceID::dragon_ball_legends,
     {dragon_ball_legends::kReplayFrameStart, dragon_ball_legends::kReplayFrameEnd,
      dragon_ball_legends::kReplayDrawSurfaceWidth, dragon_ball_legends::kReplayDrawSurfaceHeight,
      "dragon_ball_legends"}},
    {RestrictedTraceID::egypt_1500,
     {egypt_1500::kReplayFrameStart, egypt_1500::kReplayFrameEnd,
      egypt_1500::kReplayDrawSurfaceWidth, egypt_1500::kReplayDrawSurfaceHeight, "egypt_1500"}},
    {RestrictedTraceID::fate_grand_order,
     {fate_grand_order::kReplayFrameStart, fate_grand_order::kReplayFrameEnd,
      fate_grand_order::kReplayDrawSurfaceWidth, fate_grand_order::kReplayDrawSurfaceHeight,
      "fate_grand_order"}},
    {RestrictedTraceID::free_fire,
     {free_fire::kReplayFrameStart, free_fire::kReplayFrameEnd, free_fire::kReplayDrawSurfaceWidth,
      free_fire::kReplayDrawSurfaceHeight, "free_fire"}},
    {RestrictedTraceID::kartrider_rush,
     {kartrider_rush::kReplayFrameStart, kartrider_rush::kReplayFrameEnd,
      kartrider_rush::kReplayDrawSurfaceWidth, kartrider_rush::kReplayDrawSurfaceHeight,
      "kartrider_rush"}},
    {RestrictedTraceID::manhattan_10,
     {manhattan_10::kReplayFrameStart, manhattan_10::kReplayFrameEnd,
      manhattan_10::kReplayDrawSurfaceWidth, manhattan_10::kReplayDrawSurfaceHeight,
      "manhattan_10"}},
    {RestrictedTraceID::marvel_contest_of_champions,
     {marvel_contest_of_champions::kReplayFrameStart, marvel_contest_of_champions::kReplayFrameEnd,
      marvel_contest_of_champions::kReplayDrawSurfaceWidth,
      marvel_contest_of_champions::kReplayDrawSurfaceHeight, "marvel_contest_of_champions"}},
    {RestrictedTraceID::mobile_legends,
     {mobile_legends::kReplayFrameStart, mobile_legends::kReplayFrameEnd,
      mobile_legends::kReplayDrawSurfaceWidth, mobile_legends::kReplayDrawSurfaceHeight,
      "mobile_legends"}},
    {RestrictedTraceID::nba2k20_800,
     {nba2k20_800::kReplayFrameStart, nba2k20_800::kReplayFrameEnd,
      nba2k20_800::kReplayDrawSurfaceWidth, nba2k20_800::kReplayDrawSurfaceHeight, "nba2k20_800"}},
    {RestrictedTraceID::pubg_mobile_lite,
     {pubg_mobile_lite::kReplayFrameStart, pubg_mobile_lite::kReplayFrameEnd,
      pubg_mobile_lite::kReplayDrawSurfaceWidth, pubg_mobile_lite::kReplayDrawSurfaceHeight,
      "pubg_mobile_lite"}},
    {RestrictedTraceID::temple_run_300,
     {temple_run_300::kReplayFrameStart, temple_run_300::kReplayFrameEnd,
      temple_run_300::kReplayDrawSurfaceWidth, temple_run_300::kReplayDrawSurfaceHeight,
      "temple_run_300"}},
    {RestrictedTraceID::trex_200,
     {trex_200::kReplayFrameStart, trex_200::kReplayFrameEnd, trex_200::kReplayDrawSurfaceWidth,
      trex_200::kReplayDrawSurfaceHeight, "trex_200"}},
    {RestrictedTraceID::world_of_tanks_blitz,
     {world_of_tanks_blitz::kReplayFrameStart, world_of_tanks_blitz::kReplayFrameEnd,
      world_of_tanks_blitz::kReplayDrawSurfaceWidth, world_of_tanks_blitz::kReplayDrawSurfaceHeight,
      "world_of_tanks_blitz"}}};
}

const TraceInfo &GetTraceInfo(RestrictedTraceID traceID)
{
    return kTraceInfos[traceID];
}

void ReplayFrame(RestrictedTraceID traceID, uint32_t frameIndex)
{
    switch (traceID)
    {
        case RestrictedTraceID::angry_birds_2_1500:
            angry_birds_2_1500::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::arena_of_valor:
            arena_of_valor::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::brawl_stars:
            brawl_stars::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::candy_crush_500:
            candy_crush_500::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::clash_of_clans:
            clash_of_clans::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::cod_mobile:
            cod_mobile::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::dragon_ball_legends:
            dragon_ball_legends::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::egypt_1500:
            egypt_1500::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::fate_grand_order:
            fate_grand_order::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::free_fire:
            free_fire::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::kartrider_rush:
            kartrider_rush::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::manhattan_10:
            manhattan_10::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::marvel_contest_of_champions:
            marvel_contest_of_champions::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::mobile_legends:
            mobile_legends::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::nba2k20_800:
            nba2k20_800::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::pubg_mobile_lite:
            pubg_mobile_lite::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::temple_run_300:
            temple_run_300::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::trex_200:
            trex_200::ReplayContext1Frame(frameIndex);
            break;
        case RestrictedTraceID::world_of_tanks_blitz:
            world_of_tanks_blitz::ReplayContext1Frame(frameIndex);
            break;
        default:
            fprintf(stderr, "Error in switch.\n");
            assert(0);
            break;
    }
}

void ResetReplay(RestrictedTraceID traceID)
{
    switch (traceID)
    {
        case RestrictedTraceID::angry_birds_2_1500:
            angry_birds_2_1500::ResetContext1Replay();
            break;
        case RestrictedTraceID::arena_of_valor:
            arena_of_valor::ResetContext1Replay();
            break;
        case RestrictedTraceID::brawl_stars:
            brawl_stars::ResetContext1Replay();
            break;
        case RestrictedTraceID::candy_crush_500:
            candy_crush_500::ResetContext1Replay();
            break;
        case RestrictedTraceID::clash_of_clans:
            clash_of_clans::ResetContext1Replay();
            break;
        case RestrictedTraceID::cod_mobile:
            cod_mobile::ResetContext1Replay();
            break;
        case RestrictedTraceID::dragon_ball_legends:
            dragon_ball_legends::ResetContext1Replay();
            break;
        case RestrictedTraceID::egypt_1500:
            egypt_1500::ResetContext1Replay();
            break;
        case RestrictedTraceID::fate_grand_order:
            fate_grand_order::ResetContext1Replay();
            break;
        case RestrictedTraceID::free_fire:
            free_fire::ResetContext1Replay();
            break;
        case RestrictedTraceID::kartrider_rush:
            kartrider_rush::ResetContext1Replay();
            break;
        case RestrictedTraceID::manhattan_10:
            manhattan_10::ResetContext1Replay();
            break;
        case RestrictedTraceID::marvel_contest_of_champions:
            marvel_contest_of_champions::ResetContext1Replay();
            break;
        case RestrictedTraceID::mobile_legends:
            mobile_legends::ResetContext1Replay();
            break;
        case RestrictedTraceID::nba2k20_800:
            nba2k20_800::ResetContext1Replay();
            break;
        case RestrictedTraceID::pubg_mobile_lite:
            pubg_mobile_lite::ResetContext1Replay();
            break;
        case RestrictedTraceID::temple_run_300:
            temple_run_300::ResetContext1Replay();
            break;
        case RestrictedTraceID::trex_200:
            trex_200::ResetContext1Replay();
            break;
        case RestrictedTraceID::world_of_tanks_blitz:
            world_of_tanks_blitz::ResetContext1Replay();
            break;
        default:
            fprintf(stderr, "Error in switch.\n");
            assert(0);
            break;
    }
}

void SetupReplay(RestrictedTraceID traceID)
{
    switch (traceID)
    {
        case RestrictedTraceID::angry_birds_2_1500:
            angry_birds_2_1500::SetupContext1Replay();
            break;
        case RestrictedTraceID::arena_of_valor:
            arena_of_valor::SetupContext1Replay();
            break;
        case RestrictedTraceID::brawl_stars:
            brawl_stars::SetupContext1Replay();
            break;
        case RestrictedTraceID::candy_crush_500:
            candy_crush_500::SetupContext1Replay();
            break;
        case RestrictedTraceID::clash_of_clans:
            clash_of_clans::SetupContext1Replay();
            break;
        case RestrictedTraceID::cod_mobile:
            cod_mobile::SetupContext1Replay();
            break;
        case RestrictedTraceID::dragon_ball_legends:
            dragon_ball_legends::SetupContext1Replay();
            break;
        case RestrictedTraceID::egypt_1500:
            egypt_1500::SetupContext1Replay();
            break;
        case RestrictedTraceID::fate_grand_order:
            fate_grand_order::SetupContext1Replay();
            break;
        case RestrictedTraceID::free_fire:
            free_fire::SetupContext1Replay();
            break;
        case RestrictedTraceID::kartrider_rush:
            kartrider_rush::SetupContext1Replay();
            break;
        case RestrictedTraceID::manhattan_10:
            manhattan_10::SetupContext1Replay();
            break;
        case RestrictedTraceID::marvel_contest_of_champions:
            marvel_contest_of_champions::SetupContext1Replay();
            break;
        case RestrictedTraceID::mobile_legends:
            mobile_legends::SetupContext1Replay();
            break;
        case RestrictedTraceID::nba2k20_800:
            nba2k20_800::SetupContext1Replay();
            break;
        case RestrictedTraceID::pubg_mobile_lite:
            pubg_mobile_lite::SetupContext1Replay();
            break;
        case RestrictedTraceID::temple_run_300:
            temple_run_300::SetupContext1Replay();
            break;
        case RestrictedTraceID::trex_200:
            trex_200::SetupContext1Replay();
            break;
        case RestrictedTraceID::world_of_tanks_blitz:
            world_of_tanks_blitz::SetupContext1Replay();
            break;
        default:
            fprintf(stderr, "Error in switch.\n");
            assert(0);
            break;
    }
}

void SetBinaryDataDir(RestrictedTraceID traceID, const char *dataDir)
{
    switch (traceID)
    {
        case RestrictedTraceID::angry_birds_2_1500:
            angry_birds_2_1500::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::arena_of_valor:
            arena_of_valor::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::brawl_stars:
            brawl_stars::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::candy_crush_500:
            candy_crush_500::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::clash_of_clans:
            clash_of_clans::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::cod_mobile:
            cod_mobile::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::dragon_ball_legends:
            dragon_ball_legends::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::egypt_1500:
            egypt_1500::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::fate_grand_order:
            fate_grand_order::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::free_fire:
            free_fire::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::kartrider_rush:
            kartrider_rush::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::manhattan_10:
            manhattan_10::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::marvel_contest_of_champions:
            marvel_contest_of_champions::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::mobile_legends:
            mobile_legends::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::nba2k20_800:
            nba2k20_800::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::pubg_mobile_lite:
            pubg_mobile_lite::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::temple_run_300:
            temple_run_300::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::trex_200:
            trex_200::SetBinaryDataDir(dataDir);
            break;
        case RestrictedTraceID::world_of_tanks_blitz:
            world_of_tanks_blitz::SetBinaryDataDir(dataDir);
            break;
        default:
            fprintf(stderr, "Error in switch.\n");
            assert(0);
            break;
    }
}

void SetBinaryDataDecompressCallback(RestrictedTraceID traceID, DecompressCallback callback)
{
    switch (traceID)
    {
        case RestrictedTraceID::angry_birds_2_1500:
            angry_birds_2_1500::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::arena_of_valor:
            arena_of_valor::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::brawl_stars:
            brawl_stars::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::candy_crush_500:
            candy_crush_500::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::clash_of_clans:
            clash_of_clans::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::cod_mobile:
            cod_mobile::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::dragon_ball_legends:
            dragon_ball_legends::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::egypt_1500:
            egypt_1500::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::fate_grand_order:
            fate_grand_order::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::free_fire:
            free_fire::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::kartrider_rush:
            kartrider_rush::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::manhattan_10:
            manhattan_10::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::marvel_contest_of_champions:
            marvel_contest_of_champions::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::mobile_legends:
            mobile_legends::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::nba2k20_800:
            nba2k20_800::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::pubg_mobile_lite:
            pubg_mobile_lite::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::temple_run_300:
            temple_run_300::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::trex_200:
            trex_200::SetBinaryDataDecompressCallback(callback);
            break;
        case RestrictedTraceID::world_of_tanks_blitz:
            world_of_tanks_blitz::SetBinaryDataDecompressCallback(callback);
            break;
        default:
            fprintf(stderr, "Error in switch.\n");
            assert(0);
            break;
    }
}
}  // namespace angle
