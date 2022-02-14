workspace "Paper"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Paper"
	location "Paper"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"P_PLATFORM_WINDOWS",
			"P_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "P_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "P_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "P_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Paper/vendor/spdlog/include",
		"Paper/src"
	}

	links
	{
		"Paper"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

	defines
		{
			"P_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "P_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "P_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "P_DIST"
		optimize "On"