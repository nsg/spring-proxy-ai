#include "json_converters.h"
#include <string.h>
#include <limits.h>

void from_json(const json& j, struct Command& c) {
    c.command = j.at("command").get<int>();
    c.data = j.at("data").get<json>();
}

void from_json(const json& j, struct SSendTextMessageCommand& c) {
    c.text = strdup(j.at("text").get<std::string>().c_str()); // This needs to be freed
    c.zone = j.at("zone").get<int>();
}

void from_json(const json& j, struct SMoveUnitCommand& c) {
    c.unitId = j.at("unitId").get<int>();
    c.groupId = j.at("groupId").get<int>();
    c.options = j.at("options").get<short>();
    c.timeOut = INT_MAX;
    float *toPos = new float[3];
    toPos[0] = j.at("toPos").at("x").get<float>();
    toPos[1] = j.at("toPos").at("y").get<float>();
    toPos[2] = j.at("toPos").at("z").get<float>();
    c.toPos_posF3 = toPos; // This also needs to be freed
}

void to_json(json& j, const SInitEvent& e) {
    j = json{{"skirmishAIId", e.skirmishAIId}};
}

void to_json(json& j, const SReleaseEvent& e) {
    j = json{{"reason", e.reason}};
}

void to_json(json& j, const SUpdateEvent& e) {
    j = json{{"frame", e.frame}};
}

void to_json(json& j, const SMessageEvent& e) {
    j = json{{"player", e.player}, {"message", e.message}};
}

void to_json(json& j, const SLuaMessageEvent& e) {
    j = json{{"inData", e.inData}};
}

void to_json(json& j, const SUnitCreatedEvent& e) {
    j = json{{"unit", e.unit}, {"builder", e.builder}};
}

void to_json(json& j, const SUnitFinishedEvent& e) {
    j = json{{"unit", e.unit}};
}

void to_json(json& j, const SUnitIdleEvent& e) {
    j = json{{"unit", e.unit}};
}

void to_json(json& j, const SUnitMoveFailedEvent& e) {
    j = json{{"unit", e.unit}};
}

void to_json(json& j, const SUnitDamagedEvent& e) {
    j = json{
        {"unit", e.unit},
        {"attacker", e.attacker},
        {"damage", e.damage},
        {"dir", json{{"x", e.dir_posF3[0]}, {"y", e.dir_posF3[1]}, {"z", e.dir_posF3[2]},}},
        {"weaponDefId", e.weaponDefId},
        {"paralyzer", e.paralyzer}
    };
}

void to_json(json& j, const SUnitDestroyedEvent& e) {
    j = json{{"unit", e.unit}, {"attacker", e.attacker}};
}

void to_json(json& j, const SUnitGivenEvent& e) {
    j = json{{"unitId", e.unitId}, {"oldTeamId", e.oldTeamId}, {"newTeamId", e.newTeamId}};
}

void to_json(json& j, const SUnitCapturedEvent& e) {
    j = json{{"unitId", e.unitId}, {"oldTeamId", e.oldTeamId}, {"newTeamId", e.newTeamId}};
}

void to_json(json& j, const SEnemyEnterLOSEvent& e) {
    j = json{{"enemy", e.enemy}};
}

void to_json(json& j, const SEnemyLeaveLOSEvent& e) {
    j = json{{"enemy", e.enemy}};
}

void to_json(json& j, const SEnemyEnterRadarEvent& e) {
    j = json{{"enemy", e.enemy}};
}

void to_json(json& j, const SEnemyLeaveRadarEvent& e) {
    j = json{{"enemy", e.enemy}};
}

void to_json(json& j, const SEnemyDamagedEvent& e) {
    j = json{
        {"enemy", e.enemy},
        {"attacker", e.attacker},
        {"damage", e.damage},
        {"dir", json{{"x", e.dir_posF3[0]}, {"y", e.dir_posF3[1]}, {"z", e.dir_posF3[2]},}},
        {"weaponDefId", e.weaponDefId},
        {"paralyzer", e.paralyzer}
    };
}

void to_json(json& j, const SEnemyDestroyedEvent& e) {
    j = json{{"enemy", e.enemy}, {"attacker", e.attacker}};
}

void to_json(json& j, const SWeaponFiredEvent& e) {
    j = json{{"unitId", e.unitId}, {"weaponDefId", e.weaponDefId}};
}

void to_json(json& j, const SPlayerCommandEvent& e) {
    j = json{{"commandTopicId", e.commandTopicId}, {"playerId", e.playerId}};
//     {
// 	int* unitIds;
// 	int unitIds_size;
// 	/// see COMMAND_* defines in AISCommands.h
// 	int commandTopicId;
// 	/// Id of the player that issued the command
// 	int playerId;
// }; //$ EVENT_PLAYER_COMMAND

}

void to_json(json& j, const SCommandFinishedEvent& e) {
    j = json{{"unitId", e.unitId}, {"commandId", e.commandId}, {"commandTopicId", e.commandTopicId}};
}

void to_json(json& j, const SSeismicPingEvent& e) {
    j = json{
        {"strength", e.strength},
        {"pos", json{{"x", e.pos_posF3[0]}, {"y", e.pos_posF3[1]}, {"z", e.pos_posF3[2]},}},
    };
}

void to_json(json& j, const SLoadEvent& e) {
    j = json{{"file", e.file}};
}

void to_json(json& j, const SSaveEvent& e) {
    j = json{{"file", e.file}};
}

void to_json(json& j, const SEnemyCreatedEvent& e) {
    j = json{{"enemy", e.enemy}};
}

void to_json(json& j, const SEnemyFinishedEvent& e) {
    j = json{{"enemy", e.enemy}};
}
