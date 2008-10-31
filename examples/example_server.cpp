/*
 * Simple example showing how to set-up a REST server using HTTP protocol
 * please note that the example doesn't even compile yet, it is used as a basis
 * to complete our API implementation.
 */

// do not include stuff, for now, just present something like 'pseudo-code'

class my_controller : public nanogear::rest::controller {
public:
    virtual void handle(const nanogear::rest::data::request& request,
                        const nanogear::rest::data::response& response)
    {
        response.set_entity("Hello world!", media_type::TEXT_PLAIN);
    }
};

int main(int argc, char** argv)
{
    my_controller c;
    server s(protocol::HTTP, 8192, c);
    s.start();
    return 0;
}
