#include <limits.h>
#include "gtest/gtest.h"

using namespace std;
#include "database.h"

// Tests composer class

TEST(ComposerTest, FirstName) {
    Composer c;
    c.set_first_name("John");
    EXPECT_EQ("John",c.first_name());
}

TEST(ComposerTest, LastName) {
    Composer c;
    c.set_last_name("Smith");
    EXPECT_EQ("Smith",c.last_name());
}

TEST(ComposerTest, Yob) {
    Composer c;
    c.set_composer_yob(1900);
    EXPECT_EQ(1900,c.composer_yob());
}

TEST(ComposerTest, Genre) {
    Composer c;
    c.set_composer_genre("Classical");
    EXPECT_EQ("Classical",c.composer_genre());
}

TEST(ComposerTest, Ranking) {
    Composer c;
    c.set_ranking(5);
    EXPECT_EQ(5,c.ranking());
}

TEST(ComposerTest, Fact) {
    Composer c;
    c.set_fact("FooBar");
    EXPECT_EQ("FooBar",c.fact());
}

TEST(ComposerTest, Promote) {
    Composer c;
    c.Promote(5);
    EXPECT_EQ(15,c.ranking());
}

TEST(ComposerTest, Demote) {
    Composer c;
    c.Demote(5);
    EXPECT_EQ(5,c.ranking());
}

// Tests database class

TEST(DatabaseTest, AddComposer) {
    Database db;
    db.AddComposer("foo", "bar", "baz", 1, "test");
    EXPECT_EQ("foo", db.GetComposer("bar").first_name());
    EXPECT_EQ("bar", db.GetComposer("bar").last_name());
    EXPECT_EQ("baz", db.GetComposer("bar").composer_genre());
    EXPECT_EQ(1, db.GetComposer("bar").composer_yob());
    EXPECT_EQ("test", db.GetComposer("bar").fact());
}

