#ifndef __JSON_CONVERTERS_H__
#define __JSON_CONVERTERS_H__
#include "ExternalAI/Interface/AISEvents.h"
#include "ExternalAI/Interface/AISCommands.h"
#include "json.hpp"

using nlohmann::json;

struct Command {
    int command;
    json data;
};

// Command deserializers
void from_json(const json& j, struct Command& c);
void from_json(const json& j, struct SSendTextMessageCommand& c);
void from_json(const json& j, struct SMoveUnitCommand& c);

// Event serializers
void to_json(json& j, const SInitEvent& e);
void to_json(json& j, const SReleaseEvent& e);
void to_json(json& j, const SUpdateEvent& e);
void to_json(json& j, const SMessageEvent& e);
void to_json(json& j, const SLuaMessageEvent& e);
void to_json(json& j, const SUnitCreatedEvent& e);
void to_json(json& j, const SUnitFinishedEvent& e);
void to_json(json& j, const SUnitIdleEvent& e);
void to_json(json& j, const SUnitMoveFailedEvent& e);
void to_json(json& j, const SUnitDamagedEvent& e);
void to_json(json& j, const SUnitDestroyedEvent& e);
void to_json(json& j, const SUnitGivenEvent& e);
void to_json(json& j, const SUnitCapturedEvent& e);
void to_json(json& j, const SEnemyEnterLOSEvent& e);
void to_json(json& j, const SEnemyLeaveLOSEvent& e);
void to_json(json& j, const SEnemyEnterRadarEvent& e);
void to_json(json& j, const SEnemyLeaveRadarEvent& e);
void to_json(json& j, const SEnemyDamagedEvent& e);
void to_json(json& j, const SEnemyDestroyedEvent& e);
void to_json(json& j, const SWeaponFiredEvent& e);
void to_json(json& j, const SPlayerCommandEvent& e);
void to_json(json& j, const SCommandFinishedEvent& e);
void to_json(json& j, const SSeismicPingEvent& e);
void to_json(json& j, const SLoadEvent& e);
void to_json(json& j, const SSaveEvent& e);
void to_json(json& j, const SEnemyCreatedEvent& e);
void to_json(json& j, const SEnemyFinishedEvent& e);
#endif
