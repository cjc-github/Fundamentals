use helloproto::greeter_client::GreeterClient;
use helloproto::HelloRequest;

pub mod helloproto {
    tonic::include_proto!("firestproto");
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    // 客户端
    let mut client = GreeterClient::connect("http://127.0.0.1:50051").await?;

    // 发送请求
    let request = tonic::Request::new(HelloRequest {
        name: "Tonic".into(),
    });

    let response = client.say_hello(request).await?;

    println!("RESPONSE={:?}", response);

    Ok(())
}
