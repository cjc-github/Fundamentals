use std::{env, path::PathBuf};

// 返回Result类型
fn main() -> Result<(), Box<dyn std::error::Error>> {
    // tonic_build库来变异制定的Protocol文件
    tonic_build::compile_protos("proto/sample.proto")?;
    //tonic_build::compile_protos("proto/route_guide.proto")?;
    // tonic_build::compile_protos("proto/echo.proto")?;

    let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
    tonic_build::configure()
        .file_descriptor_set_path(out_dir.join("stream_descriptor.bin"))
        .compile(&["proto/echo.proto"], &["proto"])
        .unwrap();

    Ok(())
}
