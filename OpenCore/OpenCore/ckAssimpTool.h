#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

struct ck_aiVectorKey
{
	aiVector3D mValue;
	float mTime;
};

struct ck_aiQuaternionKey//四元数旋转表示的关键帧值
{
	aiQuaternion mValue;
	float mTime;//当前关键帧时间点
};

struct ck_aiAnimNode
{
	std::string mNodeAnimName;//当前骨骼节点的名称
	std::vector<ck_aiVectorKey> mScalingKeys; //scale
	std::vector<ck_aiVectorKey> mPositionKeys; // position
	std::vector<ck_aiQuaternionKey> mRotationKeys; //rotation
};

struct ck_aiAnimation
{
	float mTicksPerSecond;//当前动画一秒钟等于多少ticks数
	float mDuration;//当前动画持续的时间(以ticks数量表示)
	std::vector<ck_aiAnimNode*> mChannelVec;//当前动画是有多少个骨骼运动影响的
};

struct ck_aiNode
{
	std::vector<ck_aiNode*> mChildrenVec;
	std::string mNodeName;
	aiMatrix4x4 mTransform;
};

struct ck_aiScene
{
	ck_aiNode* mRootNode;
	std::vector<ck_aiAnimation*> mAnimationVec;
};
