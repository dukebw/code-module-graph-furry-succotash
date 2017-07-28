#include "imgui_impl_glfw.h"
#include "imgui/imgui.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cstdio>

static void
error_callback(int error, const char* description)
{
        fprintf(stderr, "Error %d: %s\n", error, description);
}

int main(void)
{
        glfwSetErrorCallback(error_callback);
        if (!glfwInit())
                return EXIT_FAILURE;

        GLFWwindow *window = glfwCreateWindow(1280,
                                              720,
                                              "ImGui OpenGL2 example",
                                              NULL,
                                              NULL);
        assert(window != NULL);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        ImGui_ImplGlfw_Init(window, true);

        ImVec4 clear_color = ImColor(114, 144, 154);

        while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
                ImGui_ImplGlfw_NewFrame();

                static float f = 0.0f;
                ImGui::Text("Hello, world!");
                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
                ImGui::ColorEdit3("clear color", (float*)&clear_color);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                            1000.0f / ImGui::GetIO().Framerate,
                            ImGui::GetIO().Framerate);

                int32_t display_w;
                int32_t display_h;
                glfwGetFramebufferSize(window, &display_w, &display_h);
                glViewport(0, 0, display_w, display_h);
                glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
                glClear(GL_COLOR_BUFFER_BIT);

                ImGui::Render();
                glfwSwapBuffers(window);
        }

        return EXIT_SUCCESS;
}
