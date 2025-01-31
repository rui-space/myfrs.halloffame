// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Common.proto

#include "Common.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace Common {
class PlayerStatsDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PlayerStats>
      _instance;
} _PlayerStats_default_instance_;
class PlayerScoreDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PlayerScore>
      _instance;
} _PlayerScore_default_instance_;
}  // namespace Common
namespace protobuf_Common_2eproto {
void InitDefaultsPlayerStatsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::Common::_PlayerStats_default_instance_;
    new (ptr) ::Common::PlayerStats();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Common::PlayerStats::InitAsDefaultInstance();
}

void InitDefaultsPlayerStats() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsPlayerStatsImpl);
}

void InitDefaultsPlayerScoreImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_Common_2eproto::InitDefaultsPlayerStats();
  {
    void* ptr = &::Common::_PlayerScore_default_instance_;
    new (ptr) ::Common::PlayerScore();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Common::PlayerScore::InitAsDefaultInstance();
}

void InitDefaultsPlayerScore() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsPlayerScoreImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, score_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, score_leader_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, score_follower_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, rank_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, accuracy_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerStats, collectible_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerScore, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Common::PlayerScore, values_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Common::PlayerStats)},
  { 11, -1, sizeof(::Common::PlayerScore)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::Common::_PlayerStats_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::Common::_PlayerScore_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "Common.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\014Common.proto\022\006Common\"\177\n\013PlayerStats\022\r\n"
      "\005score\030\001 \001(\r\022\024\n\014score_leader\030\002 \001(\r\022\026\n\016sc"
      "ore_follower\030\003 \001(\r\022\014\n\004rank\030\004 \001(\r\022\020\n\010accu"
      "racy\030\005 \001(\002\022\023\n\013collectible\030\006 \001(\r\"2\n\013Playe"
      "rScore\022#\n\006values\030\001 \003(\0132\023.Common.PlayerSt"
      "atsb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 211);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Common.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_Common_2eproto
namespace Common {

// ===================================================================

void PlayerStats::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PlayerStats::kScoreFieldNumber;
const int PlayerStats::kScoreLeaderFieldNumber;
const int PlayerStats::kScoreFollowerFieldNumber;
const int PlayerStats::kRankFieldNumber;
const int PlayerStats::kAccuracyFieldNumber;
const int PlayerStats::kCollectibleFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PlayerStats::PlayerStats()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_Common_2eproto::InitDefaultsPlayerStats();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Common.PlayerStats)
}
PlayerStats::PlayerStats(const PlayerStats& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&score_, &from.score_,
    static_cast<size_t>(reinterpret_cast<char*>(&collectible_) -
    reinterpret_cast<char*>(&score_)) + sizeof(collectible_));
  // @@protoc_insertion_point(copy_constructor:Common.PlayerStats)
}

void PlayerStats::SharedCtor() {
  ::memset(&score_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&collectible_) -
      reinterpret_cast<char*>(&score_)) + sizeof(collectible_));
  _cached_size_ = 0;
}

PlayerStats::~PlayerStats() {
  // @@protoc_insertion_point(destructor:Common.PlayerStats)
  SharedDtor();
}

void PlayerStats::SharedDtor() {
}

void PlayerStats::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PlayerStats::descriptor() {
  ::protobuf_Common_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Common_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PlayerStats& PlayerStats::default_instance() {
  ::protobuf_Common_2eproto::InitDefaultsPlayerStats();
  return *internal_default_instance();
}

PlayerStats* PlayerStats::New(::google::protobuf::Arena* arena) const {
  PlayerStats* n = new PlayerStats;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PlayerStats::Clear() {
// @@protoc_insertion_point(message_clear_start:Common.PlayerStats)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&score_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&collectible_) -
      reinterpret_cast<char*>(&score_)) + sizeof(collectible_));
  _internal_metadata_.Clear();
}

bool PlayerStats::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Common.PlayerStats)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 score = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 score_leader = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_leader_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 score_follower = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_follower_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 rank = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &rank_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float accuracy = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(45u /* 45 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &accuracy_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 collectible = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &collectible_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Common.PlayerStats)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Common.PlayerStats)
  return false;
#undef DO_
}

void PlayerStats::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Common.PlayerStats)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 score = 1;
  if (this->score() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->score(), output);
  }

  // uint32 score_leader = 2;
  if (this->score_leader() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->score_leader(), output);
  }

  // uint32 score_follower = 3;
  if (this->score_follower() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->score_follower(), output);
  }

  // uint32 rank = 4;
  if (this->rank() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->rank(), output);
  }

  // float accuracy = 5;
  if (this->accuracy() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->accuracy(), output);
  }

  // uint32 collectible = 6;
  if (this->collectible() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->collectible(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Common.PlayerStats)
}

::google::protobuf::uint8* PlayerStats::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Common.PlayerStats)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 score = 1;
  if (this->score() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->score(), target);
  }

  // uint32 score_leader = 2;
  if (this->score_leader() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->score_leader(), target);
  }

  // uint32 score_follower = 3;
  if (this->score_follower() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->score_follower(), target);
  }

  // uint32 rank = 4;
  if (this->rank() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->rank(), target);
  }

  // float accuracy = 5;
  if (this->accuracy() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->accuracy(), target);
  }

  // uint32 collectible = 6;
  if (this->collectible() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->collectible(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Common.PlayerStats)
  return target;
}

size_t PlayerStats::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Common.PlayerStats)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // uint32 score = 1;
  if (this->score() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->score());
  }

  // uint32 score_leader = 2;
  if (this->score_leader() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->score_leader());
  }

  // uint32 score_follower = 3;
  if (this->score_follower() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->score_follower());
  }

  // uint32 rank = 4;
  if (this->rank() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->rank());
  }

  // float accuracy = 5;
  if (this->accuracy() != 0) {
    total_size += 1 + 4;
  }

  // uint32 collectible = 6;
  if (this->collectible() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->collectible());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PlayerStats::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Common.PlayerStats)
  GOOGLE_DCHECK_NE(&from, this);
  const PlayerStats* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PlayerStats>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Common.PlayerStats)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Common.PlayerStats)
    MergeFrom(*source);
  }
}

void PlayerStats::MergeFrom(const PlayerStats& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Common.PlayerStats)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.score() != 0) {
    set_score(from.score());
  }
  if (from.score_leader() != 0) {
    set_score_leader(from.score_leader());
  }
  if (from.score_follower() != 0) {
    set_score_follower(from.score_follower());
  }
  if (from.rank() != 0) {
    set_rank(from.rank());
  }
  if (from.accuracy() != 0) {
    set_accuracy(from.accuracy());
  }
  if (from.collectible() != 0) {
    set_collectible(from.collectible());
  }
}

void PlayerStats::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Common.PlayerStats)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerStats::CopyFrom(const PlayerStats& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Common.PlayerStats)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerStats::IsInitialized() const {
  return true;
}

void PlayerStats::Swap(PlayerStats* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PlayerStats::InternalSwap(PlayerStats* other) {
  using std::swap;
  swap(score_, other->score_);
  swap(score_leader_, other->score_leader_);
  swap(score_follower_, other->score_follower_);
  swap(rank_, other->rank_);
  swap(accuracy_, other->accuracy_);
  swap(collectible_, other->collectible_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PlayerStats::GetMetadata() const {
  protobuf_Common_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Common_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void PlayerScore::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PlayerScore::kValuesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PlayerScore::PlayerScore()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_Common_2eproto::InitDefaultsPlayerScore();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Common.PlayerScore)
}
PlayerScore::PlayerScore(const PlayerScore& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      values_(from.values_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Common.PlayerScore)
}

void PlayerScore::SharedCtor() {
  _cached_size_ = 0;
}

PlayerScore::~PlayerScore() {
  // @@protoc_insertion_point(destructor:Common.PlayerScore)
  SharedDtor();
}

void PlayerScore::SharedDtor() {
}

void PlayerScore::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PlayerScore::descriptor() {
  ::protobuf_Common_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Common_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PlayerScore& PlayerScore::default_instance() {
  ::protobuf_Common_2eproto::InitDefaultsPlayerScore();
  return *internal_default_instance();
}

PlayerScore* PlayerScore::New(::google::protobuf::Arena* arena) const {
  PlayerScore* n = new PlayerScore;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PlayerScore::Clear() {
// @@protoc_insertion_point(message_clear_start:Common.PlayerScore)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  values_.Clear();
  _internal_metadata_.Clear();
}

bool PlayerScore::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Common.PlayerScore)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Common.PlayerStats values = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_values()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Common.PlayerScore)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Common.PlayerScore)
  return false;
#undef DO_
}

void PlayerScore::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Common.PlayerScore)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Common.PlayerStats values = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->values_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->values(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Common.PlayerScore)
}

::google::protobuf::uint8* PlayerScore::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Common.PlayerScore)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Common.PlayerStats values = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->values_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->values(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Common.PlayerScore)
  return target;
}

size_t PlayerScore::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Common.PlayerScore)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .Common.PlayerStats values = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->values_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->values(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PlayerScore::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Common.PlayerScore)
  GOOGLE_DCHECK_NE(&from, this);
  const PlayerScore* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PlayerScore>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Common.PlayerScore)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Common.PlayerScore)
    MergeFrom(*source);
  }
}

void PlayerScore::MergeFrom(const PlayerScore& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Common.PlayerScore)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  values_.MergeFrom(from.values_);
}

void PlayerScore::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Common.PlayerScore)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerScore::CopyFrom(const PlayerScore& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Common.PlayerScore)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerScore::IsInitialized() const {
  return true;
}

void PlayerScore::Swap(PlayerScore* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PlayerScore::InternalSwap(PlayerScore* other) {
  using std::swap;
  values_.InternalSwap(&other->values_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PlayerScore::GetMetadata() const {
  protobuf_Common_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Common_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Common

// @@protoc_insertion_point(global_scope)
