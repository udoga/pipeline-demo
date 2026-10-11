#include <cstring>
#include <string>
#include <gtest/gtest.h>
#include "Collector.h"
#include "Serializer.h"

namespace demo {
    class SerializableString: public Serializable {
    public:
        const std::string str;
        explicit SerializableString(const std::string& str): str(str) {}
        u32 getSize() const override { return static_cast<u32>(str.size()); }
        void serialize(u8* buffer) const override { memcpy(buffer, str.c_str(), str.size()); }
    };

    TEST(SerializerTest, writesToBufferAndEmitsSlice) {
        std::string word = "sample";
        SerializableString serializable(word);
        Serializer<SerializableString> serializer(10);
        Collector<Slice> collector;
        serializer.Emitter<Slice>::enrol(collector);
        serializer.handle(serializable);
        ASSERT_EQ(1, collector.items.size());
        EXPECT_EQ(Slice((u8*) word.c_str(), word.size()), collector.items.at(0));
    }
}
