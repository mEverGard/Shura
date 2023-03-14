workspace "Shura"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Shura"
    location "Shura"
    kind "SharedLib"
    language "C++"


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "hzpch.h"
	pchsource "Shura/src/hzpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
		"%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SH_PLATFORM_WINDOWS",
            "SH_BUILD_DLL",
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }
    
    filter "configurations:Debug"
        defines "SH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SH_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Shura/vendor/spdlog/include",
        "Shura/src"
    }


    links {
        "Shura"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SH_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "SH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SH_DIST"
        optimize "On"
   