﻿#pragma once
#include "shader.h"
#include "texture.h"
#include <ctime>
#include "common.h"
using namespace std;

namespace Fountain {

#define PARTICLE_TYPE_LAUNCHER 0.0f
#define PARTICLE_TYPE_SHELL 1.0f
	//发射粒子最大周期
#define MAX_LAUNCH_F 1.0f*1000.0f
	//发射粒子最小周期
#define MIN_LAUNCH_F 0.3f*1000.0f

	const float ANGLE = 120.0f;
	const int MAX_PARTICLES = 9000;//定义粒子发射系统最大的粒子数
	//初始发射器例子数量
	const int INIT_PARTICLES = 1500;
	//喷泉中心
	const glm::vec3 center(-300, 28, -170.0f);
	const float radius = 0.01f;

	struct WaterParticle
	{
		float type;
		glm::vec3 position;
		glm::vec3 velocity;
		float lifetimeMills;//年龄
							//float size;//粒子点精灵大小
	};

	class Fountain
	{
	public:
		Fountain();
		~Fountain();
		void Render(float frametimeMills, glm::mat4& worldMatrix, glm::mat4 viewMatrix, glm::mat4& projectMatrix);
		void RenderShadow(float frametimeMills);
		void setLightSpace(glm::mat4& lightSpaceMatrix);
	private:
		bool InitFountain();
		void UpdateParticles(float frametimeMills);//更新粒子的位置等
		void InitRandomTexture(unsigned int size);//生成1维随机纹理
		void RenderParticles(glm::mat4& worldMatrix, glm::mat4& viewMatrix, glm::mat4& projectMatrix);
		void GenInitLocation(WaterParticle partciles[], int nums);//生成初始粒子

		unsigned int mCurVBOIndex, mCurTransformFeedbackIndex;
		GLuint mParticleBuffers[2]; //粒子发射系统的两个顶点缓存区
		GLuint mParticleArrays[2];
		GLuint mTransformFeedbacks[2];//粒子发射系统对应的TransformFeedback
		GLuint mRandomTexture;//随机一维纹理
		CTexture mSparkTexture;//Alpha纹理
		CTexture mStartTexture;
		float mTimer;//粒子发射器已经发射的时间
		bool mFirst;
		Shader* mUpdateShader;//更新粒子的GPUProgram
		Shader* mRenderShader;//渲染粒子的GPUProgram
		Shader* mRenderShadow;
	};
}