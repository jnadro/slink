shader_dir = "../src/shaders/"
file_ext = ".hlsl"

if ARGV.length() == 0
	put "Usage: makeshader.rb shadername"
else
	base_file_name = ARGV[0] + "Shader" + file_ext
	base_path  = shader_dir + base_file_name

	# Shader File
	File.open(base_path, 'w') { |file|
		file.write("struct VS_INPUT {\n")
		file.write("};\n\n")

		file.write("struct VS_OUTPUT {\n")
		file.write("};\n\n")

		file.write("VS_OUTPUT VS(in VS_INPUT input)\n")
		file.write("{\n")
		file.write("\tVS_OUTPUT output = (VS_OUTPUT)0;\n")
		file.write("\n")
    	file.write("\treturn output;\n")
		file.write("}\n")

		file.write("\n\n")

		file.write("float4 PS(in VS_OUTPUT input) : SV_Target\n")
		file.write("{\n")
    	file.write("\treturn float4(1.0f, 0.0, 1.0f, 1.0f);\n")
		file.write("}\n")
	}

	# Vertex Shader
	File.open(shader_dir + ARGV[0] + "VS" + file_ext, 'w') { |file|
		file.write("#include \"#{base_file_name}\"\n")

	}

	# Pixel Shader
	File.open(shader_dir + ARGV[0] + "PS" + file_ext, 'w') { |file|
		file.write("#include \"#{base_file_name}\"\n")
	}
end