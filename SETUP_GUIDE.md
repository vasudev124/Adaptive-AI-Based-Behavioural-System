# Setup Guide - Adaptive AI Project

## Prerequisites
- Unreal Engine 5.4+
- Visual Studio 2019/2022 with C++ workload
- Basic knowledge of Unreal Engine and C++

## Step-by-Step Setup

### 1. Project Setup (2 minutes)
1. Extract the project files
2. Right-click AdaptiveAI.uproject
3. Select "Generate Visual Studio project files"

### 2. Build Project (3-5 minutes)
1. Open AdaptiveAI.sln in Visual Studio
2. Set configuration to "Development Editor"
3. Build Solution (Ctrl+Shift+B)

### 3. Open in Unreal Engine
1. Double-click AdaptiveAI.uproject
2. Wait for initial compilation and asset processing

### 4. Level Setup
1. Add NavMeshBoundsVolume to your level
2. Scale to cover playable area
3. Press 'P' to verify navigation mesh (green overlay)

### 5. Create AI Character
1. Create Blueprint based on AdaptiveNPCCharacter
2. Set skeletal mesh and animation blueprint
3. Assign behavior tree and blackboard assets
4. Place in level and test

## Troubleshooting
- Build errors: Ensure C++ workload is installed
- AI not moving: Check NavMeshBoundsVolume coverage
- Missing classes: Verify project compiled successfully

Ready to customize and extend!
