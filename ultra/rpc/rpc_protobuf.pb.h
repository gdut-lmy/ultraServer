// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc_protobuf.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_rpc_5fprotobuf_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_rpc_5fprotobuf_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_rpc_5fprotobuf_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_rpc_5fprotobuf_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_rpc_5fprotobuf_2eproto;
namespace ultraRPC {
class ultraProtocol;
class ultraProtocolDefaultTypeInternal;
extern ultraProtocolDefaultTypeInternal _ultraProtocol_default_instance_;
class ultraProtocol_MsgContent;
class ultraProtocol_MsgContentDefaultTypeInternal;
extern ultraProtocol_MsgContentDefaultTypeInternal _ultraProtocol_MsgContent_default_instance_;
}  // namespace ultraRPC
PROTOBUF_NAMESPACE_OPEN
template<> ::ultraRPC::ultraProtocol* Arena::CreateMaybeMessage<::ultraRPC::ultraProtocol>(Arena*);
template<> ::ultraRPC::ultraProtocol_MsgContent* Arena::CreateMaybeMessage<::ultraRPC::ultraProtocol_MsgContent>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace ultraRPC {

enum ultraProtocol_MsgType : int {
  ultraProtocol_MsgType_HEARTBEAT_PACKET = 0,
  ultraProtocol_MsgType_RPC_PROVIDER = 1,
  ultraProtocol_MsgType_RPC_CONSUMER = 3,
  ultraProtocol_MsgType_RPC_REQUEST = 4,
  ultraProtocol_MsgType_RPC_RESPONSE = 5,
  ultraProtocol_MsgType_RPC_METHOD_REQUEST = 6,
  ultraProtocol_MsgType_RPC_METHOD_RESPONSE = 7,
  ultraProtocol_MsgType_RPC_SERVICE_REGISTER = 8,
  ultraProtocol_MsgType_RPC_SERVICE_REGISTER_RESPONSE = 9,
  ultraProtocol_MsgType_RPC_SERVICE_DISCOVER = 10,
  ultraProtocol_MsgType_RPC_SERVICE_DISCOVER_RESPONSE = 11,
  ultraProtocol_MsgType_RPC_PUBSUB_REQUEST = 12,
  ultraProtocol_MsgType_RPC_PUBSUB_RESPONSE = 13
};
bool ultraProtocol_MsgType_IsValid(int value);
constexpr ultraProtocol_MsgType ultraProtocol_MsgType_MsgType_MIN = ultraProtocol_MsgType_HEARTBEAT_PACKET;
constexpr ultraProtocol_MsgType ultraProtocol_MsgType_MsgType_MAX = ultraProtocol_MsgType_RPC_PUBSUB_RESPONSE;
constexpr int ultraProtocol_MsgType_MsgType_ARRAYSIZE = ultraProtocol_MsgType_MsgType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ultraProtocol_MsgType_descriptor();
template<typename T>
inline const std::string& ultraProtocol_MsgType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ultraProtocol_MsgType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ultraProtocol_MsgType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ultraProtocol_MsgType_descriptor(), enum_t_value);
}
inline bool ultraProtocol_MsgType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ultraProtocol_MsgType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ultraProtocol_MsgType>(
    ultraProtocol_MsgType_descriptor(), name, value);
}
// ===================================================================

class ultraProtocol_MsgContent PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ultraRPC.ultraProtocol.MsgContent) */ {
 public:
  inline ultraProtocol_MsgContent() : ultraProtocol_MsgContent(nullptr) {}
  virtual ~ultraProtocol_MsgContent();

  ultraProtocol_MsgContent(const ultraProtocol_MsgContent& from);
  ultraProtocol_MsgContent(ultraProtocol_MsgContent&& from) noexcept
    : ultraProtocol_MsgContent() {
    *this = ::std::move(from);
  }

  inline ultraProtocol_MsgContent& operator=(const ultraProtocol_MsgContent& from) {
    CopyFrom(from);
    return *this;
  }
  inline ultraProtocol_MsgContent& operator=(ultraProtocol_MsgContent&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ultraProtocol_MsgContent& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ultraProtocol_MsgContent* internal_default_instance() {
    return reinterpret_cast<const ultraProtocol_MsgContent*>(
               &_ultraProtocol_MsgContent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ultraProtocol_MsgContent& a, ultraProtocol_MsgContent& b) {
    a.Swap(&b);
  }
  inline void Swap(ultraProtocol_MsgContent* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ultraProtocol_MsgContent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ultraProtocol_MsgContent* New() const final {
    return CreateMaybeMessage<ultraProtocol_MsgContent>(nullptr);
  }

  ultraProtocol_MsgContent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ultraProtocol_MsgContent>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ultraProtocol_MsgContent& from);
  void MergeFrom(const ultraProtocol_MsgContent& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ultraProtocol_MsgContent* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ultraRPC.ultraProtocol.MsgContent";
  }
  protected:
  explicit ultraProtocol_MsgContent(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_rpc_5fprotobuf_2eproto);
    return ::descriptor_table_rpc_5fprotobuf_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCONTENTFieldNumber = 1,
  };
  // optional string CONTENT = 1;
  bool has_content() const;
  private:
  bool _internal_has_content() const;
  public:
  void clear_content();
  const std::string& content() const;
  void set_content(const std::string& value);
  void set_content(std::string&& value);
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  std::string* mutable_content();
  std::string* release_content();
  void set_allocated_content(std::string* content);
  private:
  const std::string& _internal_content() const;
  void _internal_set_content(const std::string& value);
  std::string* _internal_mutable_content();
  public:

  // @@protoc_insertion_point(class_scope:ultraRPC.ultraProtocol.MsgContent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr content_;
  friend struct ::TableStruct_rpc_5fprotobuf_2eproto;
};
// -------------------------------------------------------------------

class ultraProtocol PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ultraRPC.ultraProtocol) */ {
 public:
  inline ultraProtocol() : ultraProtocol(nullptr) {}
  virtual ~ultraProtocol();

  ultraProtocol(const ultraProtocol& from);
  ultraProtocol(ultraProtocol&& from) noexcept
    : ultraProtocol() {
    *this = ::std::move(from);
  }

  inline ultraProtocol& operator=(const ultraProtocol& from) {
    CopyFrom(from);
    return *this;
  }
  inline ultraProtocol& operator=(ultraProtocol&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ultraProtocol& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ultraProtocol* internal_default_instance() {
    return reinterpret_cast<const ultraProtocol*>(
               &_ultraProtocol_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ultraProtocol& a, ultraProtocol& b) {
    a.Swap(&b);
  }
  inline void Swap(ultraProtocol* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ultraProtocol* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ultraProtocol* New() const final {
    return CreateMaybeMessage<ultraProtocol>(nullptr);
  }

  ultraProtocol* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ultraProtocol>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ultraProtocol& from);
  void MergeFrom(const ultraProtocol& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ultraProtocol* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ultraRPC.ultraProtocol";
  }
  protected:
  explicit ultraProtocol(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_rpc_5fprotobuf_2eproto);
    return ::descriptor_table_rpc_5fprotobuf_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef ultraProtocol_MsgContent MsgContent;

  typedef ultraProtocol_MsgType MsgType;
  static constexpr MsgType HEARTBEAT_PACKET =
    ultraProtocol_MsgType_HEARTBEAT_PACKET;
  static constexpr MsgType RPC_PROVIDER =
    ultraProtocol_MsgType_RPC_PROVIDER;
  static constexpr MsgType RPC_CONSUMER =
    ultraProtocol_MsgType_RPC_CONSUMER;
  static constexpr MsgType RPC_REQUEST =
    ultraProtocol_MsgType_RPC_REQUEST;
  static constexpr MsgType RPC_RESPONSE =
    ultraProtocol_MsgType_RPC_RESPONSE;
  static constexpr MsgType RPC_METHOD_REQUEST =
    ultraProtocol_MsgType_RPC_METHOD_REQUEST;
  static constexpr MsgType RPC_METHOD_RESPONSE =
    ultraProtocol_MsgType_RPC_METHOD_RESPONSE;
  static constexpr MsgType RPC_SERVICE_REGISTER =
    ultraProtocol_MsgType_RPC_SERVICE_REGISTER;
  static constexpr MsgType RPC_SERVICE_REGISTER_RESPONSE =
    ultraProtocol_MsgType_RPC_SERVICE_REGISTER_RESPONSE;
  static constexpr MsgType RPC_SERVICE_DISCOVER =
    ultraProtocol_MsgType_RPC_SERVICE_DISCOVER;
  static constexpr MsgType RPC_SERVICE_DISCOVER_RESPONSE =
    ultraProtocol_MsgType_RPC_SERVICE_DISCOVER_RESPONSE;
  static constexpr MsgType RPC_PUBSUB_REQUEST =
    ultraProtocol_MsgType_RPC_PUBSUB_REQUEST;
  static constexpr MsgType RPC_PUBSUB_RESPONSE =
    ultraProtocol_MsgType_RPC_PUBSUB_RESPONSE;
  static inline bool MsgType_IsValid(int value) {
    return ultraProtocol_MsgType_IsValid(value);
  }
  static constexpr MsgType MsgType_MIN =
    ultraProtocol_MsgType_MsgType_MIN;
  static constexpr MsgType MsgType_MAX =
    ultraProtocol_MsgType_MsgType_MAX;
  static constexpr int MsgType_ARRAYSIZE =
    ultraProtocol_MsgType_MsgType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  MsgType_descriptor() {
    return ultraProtocol_MsgType_descriptor();
  }
  template<typename T>
  static inline const std::string& MsgType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, MsgType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function MsgType_Name.");
    return ultraProtocol_MsgType_Name(enum_t_value);
  }
  static inline bool MsgType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      MsgType* value) {
    return ultraProtocol_MsgType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kMAGICFieldNumber = 1,
    kVERSIONFieldNumber = 2,
    kSEQUENCEIDFieldNumber = 3,
  };
  // optional int32 MAGIC = 1;
  bool has_magic() const;
  private:
  bool _internal_has_magic() const;
  public:
  void clear_magic();
  ::PROTOBUF_NAMESPACE_ID::int32 magic() const;
  void set_magic(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_magic() const;
  void _internal_set_magic(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional int32 VERSION = 2;
  bool has_version() const;
  private:
  bool _internal_has_version() const;
  public:
  void clear_version();
  ::PROTOBUF_NAMESPACE_ID::int32 version() const;
  void set_version(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_version() const;
  void _internal_set_version(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required uint32 SEQUENCE_ID = 3;
  bool has_sequence_id() const;
  private:
  bool _internal_has_sequence_id() const;
  public:
  void clear_sequence_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 sequence_id() const;
  void set_sequence_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_sequence_id() const;
  void _internal_set_sequence_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:ultraRPC.ultraProtocol)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 magic_;
  ::PROTOBUF_NAMESPACE_ID::int32 version_;
  ::PROTOBUF_NAMESPACE_ID::uint32 sequence_id_;
  friend struct ::TableStruct_rpc_5fprotobuf_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ultraProtocol_MsgContent

// optional string CONTENT = 1;
inline bool ultraProtocol_MsgContent::_internal_has_content() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ultraProtocol_MsgContent::has_content() const {
  return _internal_has_content();
}
inline void ultraProtocol_MsgContent::clear_content() {
  content_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ultraProtocol_MsgContent::content() const {
  // @@protoc_insertion_point(field_get:ultraRPC.ultraProtocol.MsgContent.CONTENT)
  return _internal_content();
}
inline void ultraProtocol_MsgContent::set_content(const std::string& value) {
  _internal_set_content(value);
  // @@protoc_insertion_point(field_set:ultraRPC.ultraProtocol.MsgContent.CONTENT)
}
inline std::string* ultraProtocol_MsgContent::mutable_content() {
  // @@protoc_insertion_point(field_mutable:ultraRPC.ultraProtocol.MsgContent.CONTENT)
  return _internal_mutable_content();
}
inline const std::string& ultraProtocol_MsgContent::_internal_content() const {
  return content_.Get();
}
inline void ultraProtocol_MsgContent::_internal_set_content(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  content_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ultraProtocol_MsgContent::set_content(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  content_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:ultraRPC.ultraProtocol.MsgContent.CONTENT)
}
inline void ultraProtocol_MsgContent::set_content(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  content_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:ultraRPC.ultraProtocol.MsgContent.CONTENT)
}
inline void ultraProtocol_MsgContent::set_content(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000001u;
  content_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:ultraRPC.ultraProtocol.MsgContent.CONTENT)
}
inline std::string* ultraProtocol_MsgContent::_internal_mutable_content() {
  _has_bits_[0] |= 0x00000001u;
  return content_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ultraProtocol_MsgContent::release_content() {
  // @@protoc_insertion_point(field_release:ultraRPC.ultraProtocol.MsgContent.CONTENT)
  if (!_internal_has_content()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return content_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ultraProtocol_MsgContent::set_allocated_content(std::string* content) {
  if (content != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  content_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), content,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:ultraRPC.ultraProtocol.MsgContent.CONTENT)
}

// -------------------------------------------------------------------

// ultraProtocol

// optional int32 MAGIC = 1;
inline bool ultraProtocol::_internal_has_magic() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ultraProtocol::has_magic() const {
  return _internal_has_magic();
}
inline void ultraProtocol::clear_magic() {
  magic_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ultraProtocol::_internal_magic() const {
  return magic_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ultraProtocol::magic() const {
  // @@protoc_insertion_point(field_get:ultraRPC.ultraProtocol.MAGIC)
  return _internal_magic();
}
inline void ultraProtocol::_internal_set_magic(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  magic_ = value;
}
inline void ultraProtocol::set_magic(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_magic(value);
  // @@protoc_insertion_point(field_set:ultraRPC.ultraProtocol.MAGIC)
}

// optional int32 VERSION = 2;
inline bool ultraProtocol::_internal_has_version() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ultraProtocol::has_version() const {
  return _internal_has_version();
}
inline void ultraProtocol::clear_version() {
  version_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ultraProtocol::_internal_version() const {
  return version_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ultraProtocol::version() const {
  // @@protoc_insertion_point(field_get:ultraRPC.ultraProtocol.VERSION)
  return _internal_version();
}
inline void ultraProtocol::_internal_set_version(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  version_ = value;
}
inline void ultraProtocol::set_version(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_version(value);
  // @@protoc_insertion_point(field_set:ultraRPC.ultraProtocol.VERSION)
}

// required uint32 SEQUENCE_ID = 3;
inline bool ultraProtocol::_internal_has_sequence_id() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ultraProtocol::has_sequence_id() const {
  return _internal_has_sequence_id();
}
inline void ultraProtocol::clear_sequence_id() {
  sequence_id_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ultraProtocol::_internal_sequence_id() const {
  return sequence_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ultraProtocol::sequence_id() const {
  // @@protoc_insertion_point(field_get:ultraRPC.ultraProtocol.SEQUENCE_ID)
  return _internal_sequence_id();
}
inline void ultraProtocol::_internal_set_sequence_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  sequence_id_ = value;
}
inline void ultraProtocol::set_sequence_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_sequence_id(value);
  // @@protoc_insertion_point(field_set:ultraRPC.ultraProtocol.SEQUENCE_ID)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ultraRPC

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::ultraRPC::ultraProtocol_MsgType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ultraRPC::ultraProtocol_MsgType>() {
  return ::ultraRPC::ultraProtocol_MsgType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_rpc_5fprotobuf_2eproto
