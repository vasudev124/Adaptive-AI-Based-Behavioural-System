# Adaptive AI Behavior System for Unreal Engine

## Overview
Advanced AI system for NPCs featuring adaptive behavior, tactical awareness, and complex decision-making.

## Features
- 9 AI Behavior States (Idle, Patrolling, Investigating, Chasing, Flanking, etc.)
- 4-Level Alert System (Unaware → Suspicious → Alert → Combat)
- Custom Behavior Tree Tasks for complex behaviors
- Component-based architecture for modularity
- Advanced perception system with dynamic ranges

## Quick Setup
1. Open AdaptiveAI.uproject in Unreal Engine 5.4+
2. Generate Visual Studio project files
3. Build in Development Editor configuration
4. Add NavMeshBoundsVolume to your level
5. Create AI character blueprints based on AdaptiveNPCCharacter

## Architecture
- **AdaptiveNPCCharacter**: Main AI character with state management
- **AdaptiveAIController**: Manages behavior trees and blackboard data
- **Custom BT Tasks**: FindCover, AdaptivePursuit, InvestigateDisturbance
- **Component System**: Modular AI capabilities

## Key Classes
1. `AAdaptiveNPCCharacter` - Main AI character
2. `AAdaptiveAIController` - AI controller with BT management
3. `UBTTask_FindCover` - Custom behavior tree task
4. `FAdaptiveAIConfig` - Configuration structure

Perfect for portfolios, job applications, and learning advanced AI techniques!
