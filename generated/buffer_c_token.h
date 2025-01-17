struct c_token_buffer
{
  c_token *Start;
  umm Count;
};

link_internal c_token_buffer
CTokenBuffer(umm ElementCount, memory_arena* Memory)
{
  c_token_buffer Result = {};

  if (ElementCount)
  {
    Result.Start = Allocate( c_token, Memory, ElementCount );
    Result.Count = ElementCount;
  }
  else
  {
    Warn("Attempted to allocate c_token_buffer of 0 length.");
  }

  return Result;
}

link_inline c_token *
Get(c_token_buffer *Buf, u32 Index)
{
  Assert(Index < Buf->Count);
  c_token *Result = Buf->Start + Index;
  return Result;
}

