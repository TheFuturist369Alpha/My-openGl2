#version 420 core
out vec4 FragColor; in vec3 myvecout;
void main() {
	FragColor = vec4(myvecout, 1.0);
}