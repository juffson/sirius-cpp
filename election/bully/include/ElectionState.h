/**
 * @file ElectionState.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <string>

#include "IRatingStrategy.h"
namespace sirius {
namespace bully {
class State;
class Engine;
class HeartbeatMessage;
class ElectionState {
 public:
  ElectionState() = default;
  virtual ~ElectionState() = 0;
  virtual State getState() = 0;
  virtual ElectionState *onHeartbeat(Engine *engine,
                                     HeartbeatMessage &message) = 0;
  virtual ElectionState *onHeartbeatRequest(Engine *engine) = 0;
  virtual ElectionState *onElection(Engine *engine,
                                    IRatingStrategy::Rating rating,
                                    const std::string &instanceName) = 0;
  virtual ElectionState *onAnswer() = 0;
  virtual ElectionState *onElectionTimeout() = 0;
};
class ActiveState : public ElectionState {};
class InactiveState : public ElectionState {};
class PassiveState : public ElectionState {};
}  // namespace bully
}  // namespace sirius
