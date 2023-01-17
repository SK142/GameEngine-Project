while (!glfwWindowShouldClose(window))
{
    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    if (DrawTriangle)
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("hi");
    ImGui::Text("hello there");
    ImGui::Checkbox("Draw Triangle", &DrawTriangle);
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();

}