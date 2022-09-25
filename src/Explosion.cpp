#include "Explosion.h"

DOGvoid Explosion::InitParticle(DOGPARTICLE& dp)
{
	// Time particle is created relative to the global running
	// time of the particle system.
	//out.initialTime = mTime;
	dp.initialTime = GetTime();

	// Flare lives for 2-4 seconds.
	dp.lifeTime = 0.2f;

	// Initial size in pixels.
	dp.size = 12.0f;

	// Give a very small initial velocity to give the flares
	// some randomness.
	//Utils::GetRandomVector(out.initialVelocity);

	// Scalar value used in vertex shader as an amplitude factor.
	dp.mass = 4.0f;

	// Start color at 50-100% intensity when born for variation.
	dp.color = DOGCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// Generate random particle on the ring in polar coordinates:
	// random radius and random angle.
	//float r = Utils::GetRandomFloat(10.0f, 14.0f);
	//float t = Utils::GetRandomFloat(0, 2.0f*D3DX_PI);

	// Convert to Cartesian coordinates.
	dp.position.x = 0.0f;
	dp.position.y = 0.0f;
	dp.position.z = 0.0f;

	dp.angle = DOGToRadian(rand() % 360);

	dp.velocity.x = rand() % 800 * cosf(dp.angle);
	dp.velocity.y = rand() % 800 * sinf(dp.angle);
}